#pragma once
#include "Entity.h"

class Enemy : public Entity {
public:
    Enemy(int startX, int startY)
        : Entity(startX, startY, "Spider", 30, 5)
    {
        sprite[0] = " /X\\ ";
        sprite[1] = "(o.o)";
        spriteHeight = 2;
    }

    void chasePlayer(int playerX, int playerY)
    {
        if (playerX % 2 == 0)
        {
            return;
        }

        if (x < playerX) 
        {
            x++;
        }
        else if (x > playerX) 
        {
            x--;
        }

        if (y < playerY) 
        {
            y++;
        }
        else if (y > playerY) 
        {
            y--;
        }
    }

    void update(int playerX, int playerY) 
    {
        chasePlayer(playerX, playerY);
    }
};