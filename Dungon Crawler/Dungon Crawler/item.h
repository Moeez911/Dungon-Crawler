#pragma once
#pragma once
#include "GameObject.h"
#include "Entity.h"
#include "String.h"

class Item : public Gameobject {
public:
    Item(int startX, int startY, String n)
        : Gameobject(startX, startY, n)
    {

    }

    virtual void use(Entity* user) {}

    virtual void draw(Screen* screen) 
    {
        Gameobject::draw(screen);
    }
};