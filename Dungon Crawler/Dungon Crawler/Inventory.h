#pragma once
#pragma once
#include "Item.h"

class Inventory 
{
public:
    Item* items[5];
    int count;

    Inventory()
    {
        count = 0;
        for (int i = 0; i < 5; i++) 
        {
            items[i] = nullptr;
        }
    }

    bool add(Item* item)
    {
        if (count >= 5)
        {
            return false;
        }

        for (int i = 0; i < 5; i++) 
        {
            if (items[i] == nullptr)
            {
                items[i] = item;
                count++;
                return true;
            }
        }
        return false;
    }

    Item* get(int index) 
    {
        if (index >= 0 && index < 5) 
        {
            return items[index];
        }
        return nullptr;
    }

    void remove(int index) 
    {
        if (index >= 0 && index < 5)
        {
            if (items[index] != nullptr) 
            {
                items[index] = nullptr;
                count--;
            }
        }
    }

    bool isFull()
    {
        return count >= 5;
    }
};