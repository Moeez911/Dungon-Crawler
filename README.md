# Dungon-CrawlerProject Report: Dungeon
<img width="1429" height="737" alt="Screenshot 2026-01-17 144846" src="https://github.com/user-attachments/assets/0a98984c-51cb-400e-abd9-cd8cb33dbb45" />
<img width="1473" height="747" alt="Screenshot 2026-01-17 144749" src="https://github.com/user-attachments/assets/a553d3e4-50ee-47f2-b0a6-bd2a20c2baca" />
<img width="1329" height="743" alt="Screenshot 2026-01-17 144732" src="https://github.com/user-attachments/assets/29439aa4-9874-4f85-a337-b02b1194240e" />
<img width="1403" height="729" alt="Screenshot 2026-01-17 144723" src="https://github.com/user-attachments/assets/c19cf73d-707b-4c02-9520-d0e49c540bdd" />
Course: Object-Oriented Programming (CP221)
Project Type: Console-Based RPG Adventure (Custom Engine)
1. Executive Summary
"Dungeon Crawler" is a text-based Role-Playing Game (RPG) developed entirely in C++ without the use of standard libraries  such as string or vector. The project serves as a comprehensive demonstration of advanced memory management, utilizing manual dynamic character arrays and pointer arithmetic.
It features a custom-built rendering engine (Screen class) that converts a 2D grid of characters into a playable visual experience. The user navigates a procedural dungeon, manages a limited inventory, and engages in tactical combat against enemies with distinct behaviors.
2. The Game Narrative
·	The Premise: The player takes on the role of Elian, the estranged son of a renowned archaeologist who vanished while exploring the "Sunken Catacombs" beneath the city. Two weeks after the disappearance, Elian receives a single, cryptic letter from his father: "It is not a tomb... it is a cage. Do not come for me."
·	The Journey: Elian ignores the warning and descends into the pitch-black catacombs. He must navigate through rooms filled with traps and ancient guardians. As he explores, he finds clues documenting a descent into madness and the discovery of a "Hollowed" corruption spreading through the stones.
·	The Climax: In the final chamber, Elian confronts the source of the corruption. He discovers that the "Guardian" protecting the exit is a corrupted entity he must defeat to escape the "cage" his father warned him about.
3. Gameplay Mechanics
·	Visual Engine: Unlike standard text adventures that scroll endlessly, this game uses a Dynamic Screen Buffer. The Screen class renders a 40x20 ASCII grid where the player controls a character (*) moving in real-time.
·	Combat System: Combat is proximity-based. When the player enters the "Kill Zone" (within 3 units) of an Enemy or Guardian, they can initiate an attack. The enemy retaliates if the player remains close.
·	Trap System: The game features static hazards (Spikes ^^^). These utilize precise collision detection; stepping exactly on their coordinates pushes the player back and deals damage.
·	Inventory & Loot: The player has a limited inventory (5 slots). They must strategically collect Potions (Health) and Weapons (Damage Boosts) to survive the increasingly difficult rooms.
4. User Interface & Interaction
The application runs in a console window but uses a "Double Buffer" rendering technique to create smooth visuals without flickering.
A. The Dashboard (GameUI Class) A dedicated Heads-Up Display (HUD) renders above and below the game world.
·	Top Bar: Displays the Player's HP dynamically using visual bars (HP: [||||| ]).
·	Bottom Log: A scrolling text history (e.g., "[LOG]: You used a Potion") that manages the last 5 events, shifting them up as new actions occur.
B. The World (Room Class) The game world consists of linked Room objects.
·	* : The Player (Elian)
·	X : An Enemy (Spider)
·	^ : A Trap (Spikes)
·	! : A Potion
·	[ : The Boss (Guardian)
5. Class Architecture (16 Core Classes)
The project is divided into 5 logical modules to distribute development workload and ensure separation of concerns.
Module A: Core Engine & Systems (4 Classes)
·	Screen: The rendering engine. Manages the 2D char array buffer and handles drawing at specific (X, Y) coordinates.
·	String: A custom string wrapper class. It replaces string by manually managing dynamic char* arrays, deep copying, and memory concatenation.
·	Menu: Handles the start-up phase, clearing the system console, and drawing the ASCII title art.
·	GameUI: Manages the HUD and the scrolling message log. It separates the "Data" (HP numbers) from the "Visuals" (Health Bars).
Module B: World Management (2 Classes)
·	Map: The world graph. It initializes all Room objects and links their pointers (north, south, east, west) to create the dungeon layout.
·	Room: The container class. It holds an array of GameObject* pointers. It acts as the "Stage" that tells every object inside it to update and draw.
Module C: Abstract Bases (3 Classes)
·	GameObject: The base parent for everything with X/Y coordinates and a name.
·	Entity: Inherits from GameObject. The base for living things, adding health, maxHealth, and damage attributes.
·	Item: Inherits from GameObject. The base for pick-up objects, defining a pure virtual use() function.
Module D: Characters & AI (3 Classes)
·	Player: The hero class. Handles keyboard input interpretation and interaction logic (picking up items, attacking).
·	Enemy: A basic enemy (Spider). Inherits from Entity and implements simple AI behavior.
·	Boss: The Boss class. Inherits from Entity but features higher stats, a larger sprite ([oo]), and a larger hitbox.
Module E: Items & Hazards (4 Classes)
·	Inventory: A storage container class. It holds a fixed array of Item* pointers and handles adding/removing/using items.
·	Potion: Inherits from Item. Restores Player HP when used.
·	Weapon: Inherits from Item. Permanently increases Player Damage when used.
·	Trap: Inherits from GameObject. A static hazard that damages the player on precise collision.
6. Application of OOP Pillars
1.	Encapsulation:
o	The Player class keeps health and inventory private. External classes must use takeDamage() or pickup(), ensuring the internal state cannot be corrupted by the Game Engine.
1.	Inheritance:
o	Enemy and Guardian both share the Entity class logic. This prevents code duplication for things like taking damage or checking if the unit is alive.
1.	Polymorphism:
o	The Room class holds a generic array of GameObject*. It calls obj->draw() on every item.
o	At runtime, the program automatically decides whether to run Potion::draw() (printing !) or Trap::draw() (printing ^), depending on what the object actually is.
1.	Abstraction:
o	The Item class forces every child (Potion/Weapon) to implement a use() function. The Inventory doesn't need to know what the item does, only that it can be used.
7. Memory Management Strategy
Since std::string and STL vectors were prohibited, memory management is handled manually:
·	Dynamic Allocation: All text (Strings) and Objects (Enemies/Items) are allocated on the Heap using new.
·	Custom Destructors: The String class implements a custom destructor (~String) to delete its internal char* array. The Inventory class deletes items when they are removed.
·	Cleanup Chain: When the game closes, the Map deletes the Rooms, and the Rooms delete the Entities. This hierarchical cleanup ensures zero memory leaks.
Its a 2D Game made in c++
