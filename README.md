# 🏰 Dungeon Crawler

### A Console-Based RPG Adventure in C++ (Custom Engine)

> **Course:** Object-Oriented Programming (CP221)
> **Summary:** A text-based RPG developed entirely in C++ without standard libraries (no `std::string` or `std::vector`). This project demonstrates advanced memory management, polymorphism, and a custom-built rendering engine.

---

## 📸 Screenshots

| **Main Menu** | **Exploration & Combat** |
|:---:|:---:|
| <img src="https://github.com/user-attachments/assets/c63ce9f6-1c4d-45d3-98f4-f2e86a9e7749" width="100%"> | <img src="https://github.com/user-attachments/assets/3a750c5d-c83f-47aa-925b-1878ccd9e9ff" width="100%"> |
| **Inventory System** | **Boss Encounter** |
| <img src="https://github.com/user-attachments/assets/723cae37-5013-47a1-bb7e-972dcfedd445" width="100%"> | <img src="https://github.com/user-attachments/assets/9c74fdc7-95d4-4ff3-856b-0aee39ecf071" width="100%"> |

---

## 📖 The Narrative

**The Premise:**
The player takes on the role of **Elian**, the estranged son of a renowned archaeologist who vanished while exploring the "Sunken Catacombs" beneath the city. Two weeks after the disappearance, Elian receives a single, cryptic letter: *"It is not a tomb... it is a cage. Do not come for me."*

**The Journey:**
Elian ignores the warning and descends into the pitch-black catacombs. He must navigate through rooms filled with traps and ancient guardians. As he explores, he finds clues documenting a descent into madness and the discovery of a "Hollowed" corruption spreading through the stones.

**The Climax:**
In the final chamber, Elian confronts the source of the corruption. He discovers that the "Guardian" protecting the exit is a corrupted entity he must defeat to escape the "cage" his father warned him about.

---

## 🎮 Gameplay Mechanics

* **Visual Engine:** Uses a **Dynamic Screen Buffer** (Double Buffering) to render a 40x20 ASCII grid without flickering.
* **Combat System:** Proximity-based combat. The player must enter the "Kill Zone" (within 3 units) to attack enemies.
* **Trap System:** Static hazards (Spikes `^^^`) with precise collision detection. Stepping on them causes damage and knockback.
* **Inventory Management:** A limited 5-slot inventory system requiring strategic collection of Potions (Health) and Weapons (Damage Boosts).

---

## 🛠️ Technical Architecture

The project is built on **16 Core Classes** divided into 5 logical modules. 

[Image of UML class diagram for RPG game architecture]

### 1. Module A: Core Engine
* **`Screen`**: Manages the 2D char array buffer for rendering.
* **`String`**: A custom wrapper class replacing `std::string`. Handles dynamic `char*` arrays and memory concatenation manually.
* **`GameUI`**: Manages the HUD (Health Bars) and scrolling Combat Log.
* **`Menu`**: Handles the start-up phase and ASCII art.

### 2. Module B: World Management
* **`Map`**: The world graph. Initializes rooms and links pointers (`north`, `south`, `east`, `west`).
* **`Room`**: A container acting as the "Stage" for GameObjects.

### 3. Module C: Abstract Bases
