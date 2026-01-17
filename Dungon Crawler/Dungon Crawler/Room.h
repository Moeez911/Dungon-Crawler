#pragma once
#include "GameObject.h"
#include "String.h"

class Room {
public:
    String name;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
    Gameobject* objects[5];
    int objectCount;

    Room(String n)
    {
        name = n;
        objectCount = 0;
        north = nullptr;
        south = nullptr; 
        east = nullptr;
        west = nullptr;

        for (int i = 0; i < 5; i++)
        {
            objects[i] = nullptr;
        }
    }

    void addObject(Gameobject* obj) 
    {
        if (objectCount < 5) 
        {
            objects[objectCount] = obj;
            objectCount++;
        }
    }

    bool checkBite(int heroX, int heroY) 
    {
        for (int i = 0; i < objectCount; i++)
        {
            if (objects[i] != nullptr) 
            {
                int dx = heroX - objects[i]->getX();
                int dy = heroY - objects[i]->getY();
                if (dx < 0)
                {
                    dx = -dx;
                }
                if (dy < 0)
                {
                    dy = -dy;
                }
                if (dx < 3 && dy < 2)
                {
                    String n = objects[i]->getName();
                    if (n == "Spider" || n == "Boss") 
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkWin(int heroX, int heroY) 
    {
        for (int i = 0; i < objectCount; i++) 
        {
            if (objects[i] != nullptr && objects[i]->getName() == "Chest") 
            {
                int dx = heroX - objects[i]->getX();
                int dy = heroY - objects[i]->getY();
                if (dx < 0)
                {
                    dx = -dx;
                } if (dy < 0)
                {
                    dy = -dy;

                }
                if (dx < 3 && dy < 2)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void update(int playerX, int playerY) 
    {
        for (int i = 0; i < objectCount; i++) 
        {
            if (objects[i] != nullptr)
            {
                objects[i]->update(playerX, playerY);
            }
        }
    }

    void draw(Screen* screen) 
    {
        for (int i = 0; i < objectCount; i++)
        {
            if (objects[i] != nullptr)
            {
                objects[i]->draw(screen);
            }
        }

        for (int x = 0; x < 40; x++) 
        {
            if (x > 15 && x < 25 && north != nullptr)
            {
                screen->drawchar(x, 4, '.');
            }
            else
            {
                screen->drawchar(x, 4, '_');
            }

            if (x > 15 && x < 25 && south != nullptr)
            {
                screen->drawchar(x, 14, '.');
            }
            else
            {
                screen->drawchar(x, 14, '_');
            }
        }

        for (int y = 5; y < 14; y++) 
        {
            if (y > 7 && y < 11 && west != nullptr)
            {
                screen->drawchar(0, y, '.');
            }
            else
            {
                screen->drawchar(0, y, '|');
            }

            if (y > 7 && y < 11 && east != nullptr)
            {
                screen->drawchar(39, y, '.');
            }
            else
            {
                screen->drawchar(39, y, '|');
            }
        }
    }
};