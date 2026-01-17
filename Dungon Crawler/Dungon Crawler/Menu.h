#pragma once
#pragma once
#include "Screen.h"
#include "String.h"

class Menu {
public:
    void drawTitle(Screen* screen) {
        screen->clear();
        String title = "=== DUNGEON CRAWLER ===";
        String press = "Press 'p' to Play";
        String quit = "Press 'q' to Quit";

        for (int i = 0; i < title.length(); i++) 
        {
            screen->drawchar(8 + i, 8, title[i]);
        }
        
        for (int i = 0; i < press.length(); i++) 
        {
            screen->drawchar(10 + i, 10, press[i]);
        }
        
        for (int i = 0; i < quit.length(); i++) 
        {
            screen->drawchar(10 + i, 11, quit[i]);
        }
        
        screen->display();
    }
};