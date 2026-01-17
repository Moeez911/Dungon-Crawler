# 🏰 Dungeon Crawler

### A Console-Based RPG Adventure in C++ (Custom Engine)

> **Course:** Object-Oriented Programming (CP221)
> **Summary:** A text-based RPG developed entirely in C++ without standard libraries (no `std::string` or `std::vector`). This project demonstrates advanced memory management, polymorphism, and a custom-built rendering engine.

---

## 📸 Screenshots

| Main Menu | Exploration & Combat |
| --- | --- |
| <img src="[https://github.com/user-attachments/assets/c19cf73d-707b-4c02-9520-d0e49c540bdd](https://github.com/user-attachments/assets/c19cf73d-707b-4c02-9520-d0e49c540bdd)" width="100%"> | <img src="[https://github.com/user-attachments/assets/a553d3e4-50ee-47f2-b0a6-bd2a20c2baca](https://github.com/user-attachments/assets/a553d3e4-50ee-47f2-b0a6-bd2a20c2baca)" width="100%"> |
| **Inventory System** | **Boss Encounter** |
| <img src="[https://github.com/user-attachments/assets/29439aa4-9874-4f85-a337-b02b1194240e](https://github.com/user-attachments/assets/29439aa4-9874-4f85-a337-b02b1194240e)" width="100%"> | <img src="[https://github.com/user-attachments/assets/0a98984c-51cb-400e-abd9-cd8cb33dbb45](https://github.com/user-attachments/assets/0a98984c-51cb-400e-abd9-cd8cb33dbb45)" width="100%"> |

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

The project is built on **16 Core Classes** divided into 5 logical modules:

### 1. Module A: Core Engine

* **`Screen`**: Manages the 2D char array buffer for rendering.
* **`String`**: A custom wrapper class replacing `std::string`. Handles dynamic `char*` arrays and memory concatenation manually.
* **`GameUI`**: Manages the HUD (Health Bars) and scrolling Combat Log.
* **`Menu`**: Handles the start-up phase and ASCII art.

### 2. Module B: World Management

* **`Map`**: The world graph. Initializes rooms and links pointers (`north`, `south`, `east`, `west`).
* **`Room`**: A container acting as the "Stage" for GameObjects.

### 3. Module C: Abstract Bases

* **`GameObject`**: Base parent for all entities with coordinates (X, Y).
* **`Entity`**: Inherits `GameObject`. Adds `health` and `damage` (for living things).
* **`Item`**: Inherits `GameObject`. Adds a pure virtual `use()` function.

### 4. Module D: Characters & AI

* **`Player`**: Handles keyboard input (`WASD`) and interactions.
* **`Enemy`**: Basic AI behavior (Spider).
* **`Boss`**: Larger sprite (`[oo]`), higher stats, and unique behavior.

### 5. Module E: Items & Hazards

* **`Inventory`**: Stores `Item*` pointers.
* **`Potion` / `Weapon**`: Restore HP or boost Damage.
* **`Trap`**: Static object causing damage on collision.

---

## 🧩 OOP Pillars Implementation

| Pillar | Implementation in Project |
| --- | --- |
| **Encapsulation** | Player health and inventory are `private`. External modification is restricted to specific methods like `takeDamage()` to prevent invalid states. |
| **Inheritance** | `Enemy` and `Guardian` inherit from `Entity`. This prevents code duplication for common logic like taking damage or movement. |
| **Polymorphism** | The Room holds a generic array of `GameObject*`. Calling `obj->draw()` automatically executes the correct function for a Spider, Potion, or Trap at runtime. |
| **Abstraction** | The `Item` class forces all children to implement `use()`. The main engine simply calls `item->use()` without needing to know the complex details of the specific item. |

---

## 💾 Memory Management Strategy

Since `std::string` and STL vectors were prohibited, this project relies on **Manual Memory Management**:

1. **Dynamic Allocation:** All text strings and game objects are allocated on the Heap using `new`.
2. **Custom Destructors:** Classes like `String` and `Inventory` implement custom destructors to prevent memory leaks by deleting internal arrays.
3. **Cleanup Chain:** A hierarchical cleanup system ensures that deleting the `Map` deletes the `Rooms`, which in turn delete all `Entities`.

---

## 🕹️ Controls

* `W`, `A`, `S`, `D` : Move Elian
* `E` : Attack (When near enemy)
* `P` : Pick Up Item
* `1` - `5` : Use Inventory Item
* `Q` : Quit Game

---

### 👨‍💻 Author

**Abdul Moeez Asif**
*Course: Object-Oriented Programming (CP221)
