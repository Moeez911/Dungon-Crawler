#pragma once
#include "Gameobject.h"
#include "String.h"

class Entity : public Gameobject 
{
protected:
    int health;
    int maxhealth;
    int damage;

public:
    Entity(int x, int y, String n, int hp, int dmg)
        : Gameobject(x, y, n)
    {
        health = hp;
        maxhealth = hp;
        damage = dmg;
    }

    bool isAlive() 
    {
        return health > 0;
    }

    void takedamage(int amount) 
    {
        health = health - amount;
        if (health < 0)
        {
            health = 0;
        }

    }

    void heal(int amount)
    {
        health = health + amount;
        if (health > maxhealth)
        {
            health = maxhealth;
        }
    }

    void increaseDamage(int amount)
    {
        damage = damage + amount;
    }

    int getdamage() 
    {
        return damage;
    }
    int gethealth() 
    {
        return health;
    }
};