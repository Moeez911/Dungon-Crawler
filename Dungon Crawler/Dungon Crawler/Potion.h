#pragma once
#pragma once
#include "Item.h"

class Potion : public Item {
public:
    Potion(int startX, int startY)
        : Item(startX, startY, "Health Potion")
    {
        sprite[0] = "(!)";
        spriteHeight = 1;
    }

    void use(Entity* user) 
    {
        user->heal(20);
    }
};