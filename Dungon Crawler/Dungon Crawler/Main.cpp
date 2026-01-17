#include <iostream>
#include "Screen.h"
#include "Player.h"
#include "Map.h"
#include "GameUI.h"
#include "String.h"
#include "Menu.h"

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

int main() {
    Screen screen(WIDTH, HEIGHT);
    Menu menu;
    char input;
    bool gameRunning = false;

    // --- MENU LOOP ---
    while (!gameRunning) 
    {
        menu.drawTitle(&screen);
        cin >> input;

        if (input == 'p') 
        {
            gameRunning = true;
        }
        if (input == 'q')
        {
            return 0;
        }
    }

    // --- GAME START ---
    Player hero(20, 9);
    Map gameMap;
    GameUI ui;

    char key;

    while (hero.gethealth() > 0)
    {
        screen.clear(); // Clears the menu

        gameMap.currentRoom->draw(&screen);
        hero.draw(&screen);
        ui.draw(&screen, &hero, gameMap.currentRoom->name);

        screen.display();
        cout << "Cmd (w/a/s/d), (e)Atk, (p)Pick, (1-5)Use > ";

        cin >> key;
        if (key == 'q')
        {
            break;
        }

        // --- INVENTORY USE ---
        if (key == '1')
        {
            Item* item = hero.inventory.get(0);
            if (item != nullptr)
            {
                item->use(&hero);
                hero.inventory.remove(0);
                ui.addLog("Used Item 1");
            }
        }
        else if (key == '2')
        {
            Item* item = hero.inventory.get(1);
            if (item != nullptr) {
                item->use(&hero);
                hero.inventory.remove(1);
                ui.addLog("Used Item 2");
            }
        }

        // --- PICK UP ---
        if (key == 'p') {
            Room* room = gameMap.currentRoom;
            bool picked = false;
            for (int i = 0; i < room->objectCount; i++)
            {
                if (room->objects[i] != nullptr)
                {

                    int dx = hero.getX() - room->objects[i]->getX();
                    int dy = hero.getY() - room->objects[i]->getY();

                    if (dx < 0)
                    {
                        dx = -dx;
                    }
                    if (dy < 0)
                    {
                        dy = -dy;
                    }

                    if (dx + dy < 3)
                    {
                        Gameobject* obj = room->objects[i];
                        // Don't pick up enemies or traps
                        String n = obj->getName();
                        if (n == "Spider" || n == "Skeleton" || n == "Guardian" || n == "Spikes")
                        {
                            continue;
                        }

                        Item* itm = (Item*)obj;

                        if (hero.pickup(itm))
                        {
                            ui.addLog("Picked up item!");
                            room->objects[i] = nullptr;
                            picked = true;
                        }
                        else
                        {
                            ui.addLog("Inventory Full!");
                        }
                    }
                }
            }
            if (!picked)
            {
                ui.addLog("Nothing to pick up.");
            }
        }

        // --- ATTACK LOGIC ---
        else if (key == 'e')
        {
            ui.addLog("You swing sword!");
            Room* room = gameMap.currentRoom;
            bool hit = false;

            for (int i = 0; i < room->objectCount; i++)
            {
                if (room->objects[i] != nullptr)
                {
                    String n = room->objects[i]->getName();

                    if (n == "Spider" || n == "Skeleton" || n == "Guardian")
                    {

                        int dx = hero.getX() - room->objects[i]->getX();
                        int dy = hero.getY() - room->objects[i]->getY();
                        if (dx < 0)
                        {
                            dx = -dx;
                        }
                        if (dy < 0)
                        {
                            dy = -dy;
                        }

                        int range = 4;
                        if (n == "Guardian")
                        {
                            range = 6;
                        }

                        if (dx + dy < range)
                        {
                            int dmg = hero.getdamage();
                            ui.addLog("HIT! Enemy takes damage.");

                            Entity* enemy = (Entity*)room->objects[i];
                            enemy->takedamage(dmg);

                            if (!enemy->isAlive())
                            {
                                ui.addLog("Enemy defeated!");
                                room->objects[i] = nullptr;
                            }
                            hit = true;
                        }
                    }
                }
            }
            if (!hit) ui.addLog("You missed.");
        }
        else {
            hero.move(key);
        }

        // --- MOVEMENT RESTRICTIONS ---
        if (hero.getY() < 5 && gameMap.currentRoom->north == nullptr)
        {
            hero.setPosition(hero.getX(), 5);
        }
        if (hero.getY() > 13 && gameMap.currentRoom->south == nullptr)
        {
            hero.setPosition(hero.getX(), 13);
        }

        if (hero.getY() < 5 && gameMap.currentRoom->north != nullptr)
        {
        }
        else if (hero.getY() > 13 && gameMap.currentRoom->south != nullptr)
        {
        }
        else
        {
            if (hero.getY() < 5)
            {
                hero.setPosition(hero.getX(), 5);
            }
            if (hero.getY() > 13)
            {
                hero.setPosition(hero.getX(), 13);
            }
        }

        gameMap.currentRoom->update(hero.getX(), hero.getY());

        // --- TRAPS (FIXED LOGIC) ---
        Room* r = gameMap.currentRoom;
        for (int i = 0; i < r->objectCount; i++)
        {
            if (r->objects[i] != nullptr)
            {

                // 1. Check Name matches Trap.h
                if (r->objects[i]->getName() == "Spikes")
                {

                    int tX = r->objects[i]->getX();
                    int tY = r->objects[i]->getY();

                    int hX = hero.getX();
                    int hY = hero.getY();

                    // 2. LOGIC: Are we standing on the spikes?
                    // Spikes are 3 wide: [tX], [tX+1], [tX+2]
                    bool onSpikesX = (hX >= tX) && (hX <= tX + 2);
                    bool onSpikesY = (hY == tY);

                    if (onSpikesX && onSpikesY)
                    {
                        ui.addLog("STEPPED ON SPIKES! [-15 HP]");
                        hero.takedamage(15);

                        // 3. Knockback (Push player DOWN off the trap)
                        hero.setPosition(hX, hY + 1);
                    }
                }
            }
        }

        // --- ENEMY BITES ---
        if (gameMap.currentRoom->checkBite(hero.getX(), hero.getY()))
        {
            ui.addLog("OUCH! You took damage.");
            hero.takedamage(10);
            hero.setPosition(hero.getX() - 2, hero.getY());

            if (hero.gethealth() <= 0)
            {
                screen.clear();
                cout << "GAME OVER" << endl;
                break;
            }
        }

        // --- ROOM NAVIGATION ---
        if (hero.getX() >= 38)
        {
            if (gameMap.currentRoom->east != nullptr)
            {
                gameMap.currentRoom = gameMap.currentRoom->east;
                hero.setPosition(2, hero.getY());
                ui.addLog("Went East.");
            }
            else hero.setPosition(37, hero.getY());
        }

        if (hero.getX() <= 1)
        {
            if (gameMap.currentRoom->west != nullptr)
            {
                gameMap.currentRoom = gameMap.currentRoom->west;
                hero.setPosition(37, hero.getY());
                ui.addLog("Went West.");
            }
            else
            {
                hero.setPosition(2, hero.getY());
            }
        }

        if (hero.getY() <= 4)
        {
            if (gameMap.currentRoom->north != nullptr)
            {
                gameMap.currentRoom = gameMap.currentRoom->north;
                hero.setPosition(hero.getX(), 13);
                ui.addLog("Went North.");
            }
            else
            {
                hero.setPosition(hero.getX(), 5);
            }
        }

        if (hero.getY() >= 14)
        {
            if (gameMap.currentRoom->south != nullptr)
            {
                gameMap.currentRoom = gameMap.currentRoom->south;
                hero.setPosition(hero.getX(), 5);
                ui.addLog("Went South.");
            }
            else
            {
                hero.setPosition(hero.getX(), 13);
            }
        }
    }

    return 0;
}