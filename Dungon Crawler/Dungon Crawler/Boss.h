#pragma once
#pragma once
#include "Enemy.h"

class Boss: public Enemy {
public:
   Boss (int startX, int startY)
        : Enemy(startX, startY)
    {
        name = "Boss"; 
        health = 100;      
        maxhealth = 100;
        damage = 15;      

        sprite[0] = "[oo]";
        sprite[1] = "/||\\";
        sprite[2] = "_/\\_";
        spriteHeight = 3;
    }

   
   void update(int playerX, int playerY)
   {
      
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
};