#pragma once
#pragma once
#include "GameObject.h"
#include "Entity.h"

class Trap : public Gameobject {
public:
    Trap(int startX, int startY)
        : Gameobject(startX, startY, "Spikes")
    {
        sprite[0] = "^^^";
        spriteHeight = 1;
    }

    void activate(Entity* victim) 
    {
        victim->takedamage(15);
    }
};