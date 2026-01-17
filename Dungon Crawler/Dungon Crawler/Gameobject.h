#pragma once
#include "Screen.h"
#include "String.h"

class Gameobject 
{
protected:
    int x;
    int y;
    String name;
    String sprite[5]; 
    int spriteHeight;

public:
    Gameobject(int startX, int startY, String n) 
    {
        x = startX;
        y = startY;
        name = n;
        spriteHeight = 0;
    }
    void setPosition(int newX, int newY) 
    {
        x = newX;
        y = newY;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    String getName()
    {
        return name;
    }

    virtual void draw(Screen* screen)
    {
        for (int i = 0; i < spriteHeight; i++) 
        {
            for (int j = 0; j < sprite[i].length(); j++) 
            {
                screen->drawchar(x + j, y + i, sprite[i][j]);
            }
        }
    }

    virtual void update(int targetX, int targetY)
    {}
};