#pragma once
#pragma once
#include "Item.h"

class Weapon : public Item {
public:
    Weapon(int startX, int startY)
        : Item(startX, startY, "Iron Sword")
    {
        sprite[0] = "{+}";
        spriteHeight = 1;
    }

    void use(Entity* user)
    {
        user->increaseDamage(5);
    }
};