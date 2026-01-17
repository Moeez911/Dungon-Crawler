#pragma once
#include "Entity.h"
#include "Inventory.h" 

class Player : public Entity 
{
public:
    Inventory inventory;

    Player(int startX, int startY)
        : Entity(startX, startY, "Hero", 100, 10)
    {
        sprite[0] = " * ";
        sprite[1] = "/|\\";
        sprite[2] = "/ \\";
        spriteHeight = 3;
    }

    void processInput(char key) 
    {
        if (key == 'w')
        {
            y--;
        }
        if (key == 's')
        {
            y++;
        }
        if (key == 'a')
        {
            x--;
        }
        if (key == 'd')
        {
            x++;
        }
    }

    void move(char key) 
    {
        processInput(key);
    }

    bool pickup(Item* item) 
    {
        return inventory.add(item);
    }
};