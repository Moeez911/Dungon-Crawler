#pragma once
#include "Room.h"
#include "Enemy.h"
#include "Potion.h"
#include "Weapon.h"
#include "Traps.h"
#include "Boss.h"

class Map {
public:
    Room* startRoom;
    Room* currentRoom;

    Map() {
        Room* r1 = new Room("Room 1");
        Room* r2 = new Room("Room 2");
        Room* r3 = new Room("Room 3");
        Room* r4 = new Room("Room 4");
        Room* r5 = new Room("Room 5");
        Room* r6 = new Room("Room 6");
        Room* r7 = new Room("Room 7");

        r1->east = r2;
        r2->west = r1;
        r3->west = r1;
        r1->east = r3;
        r3->north = r7;
        r7->south = r3;
        r7->east = r4;
        r7->west = r6;
        r6->east = r7;
        r6->west = r5;
        r5->east = r1;
        r5->south = r2;
        r2->north = r5;
        r4->west = r2;

        // Room 1
        r1->addObject(new Potion(20, 5));
       

        // Room 2
        r2->addObject(new Enemy(15, 8));
        r2->addObject(new Enemy(25, 8));
        r2->addObject(new Trap(20, 10));
        r2->addObject(new Trap(20, 11));

        // Room 3
        r3->addObject(new Enemy(30, 9));
        r3->addObject(new Potion(5, 5));
        r3->addObject(new Trap(15, 12));

        // Room 4
        r4->addObject(new Boss(20, 9));
        r4->addObject(new Trap(10, 10));
        r4->addObject(new Trap(30, 10));

        // Room 5
        r5->addObject(new Boss(20, 9));
        r5->addObject(new Potion(35, 5));

        // Room 6
        r6->addObject(new Enemy(10, 8));
        r6->addObject(new Trap(20, 9));
        r6->addObject(new Trap(21, 9));

        // Room 7
        r7->addObject(new Enemy(15, 7));
        r7->addObject(new Enemy(25, 7));
        r7->addObject(new Potion(2, 5));
        r7->addObject(new Trap(20, 12));

        startRoom = r1;
        currentRoom = startRoom;
    }
};