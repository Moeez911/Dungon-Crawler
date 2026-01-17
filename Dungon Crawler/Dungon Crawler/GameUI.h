#pragma once
#include "Screen.h"
#include "Player.h"
#include "String.h"

class GameUI {
private:
    String logs[5];

public:
    GameUI() {
        for (int i = 0; i < 5; i++) 
        {
            logs[i] = "";
        }
        addLog("Welcome to the Dungeon...");
    }

    void addLog(String message) 
    {
        for (int i = 0; i < 4; i++) 
        {
            logs[i] = logs[i + 1];
        }

        String prefix = "[LOG]: ";
        logs[4] = prefix + message;
    }

    void draw(Screen* screen, Player* player, String locationName)
    {
        for (int x = 0; x < 40; x++) 
        {
            screen->drawchar(x, 0, '=');
        }

        int hp = player->gethealth();
        int bars = hp / 10; 

        String label = "HP:[";
        for (int i = 0; i < label.length(); i++) 
        {
            screen->drawchar(1 + i, 1, label[i]);
        }

        for (int i = 0; i < 10; i++) 
        {
            char symbol = ' '; 
            if (i < bars) 
            {
                symbol = '|'; 
            }
            screen->drawchar(5 + i, 1, symbol);
        }
        screen->drawchar(15, 1, ']');

        String loc = locationName;
        for (int i = 0; i < loc.length() && i < 15; i++)
        {
            screen->drawchar(22 + i, 1, loc[i]);
        }

        for (int x = 0; x < 40; x++) 
        {
            screen->drawchar(x, 3, '=');
        }

        for (int x = 0; x < 40; x++)
        {
            screen->drawchar(x, 15, '-');
        }

        for (int i = 0; i < 4; i++) 
        {
            String line = logs[i + 1];
            for (int j = 0; j < line.length() && j < 38; j++)
            {
                screen->drawchar(1 + j, 16 + i, line[j]);
            }
        }
    }
};