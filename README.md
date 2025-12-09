
# 2D Platformer Game

A simple 2D platformer built using **C++** and **raylib**.  
Your goal is to navigate through platforms, avoid projectiles, and reach the far-right side of the screen to win.

---
##NB: 
MSYS2 MinGW UCRT needed as the build and run-time environment
raylib for graphics(assuming user already have the raylib package on his Windows machine.)

## 🎮 How to Play

Your goal is to move from the starting point to the opposite end of the window while:

- Avoiding projectiles  
- Jumping across green platforms  
- Preventing falls off the walkable platforms  
- Reaching the far-right end to win the game  

---

## 🕹️ Controls

| Action       | Key          |
|---------------|--------------|
| Move Right    | → (Right Arrow) |
| Move Left     | ← (Left Arrow)  |
| Jump          | Spacebar     |

Combine these keys to move smoothly and avoid obstacles.

---

## 🧩 Game Elements

| Element | Description |
|----------|-------------|
| **Player Character** | A sprite controlled by the player |
| **Platforms** | Colored rectangles; if you’re not standing on one, you fall |
| **Obstacles** | Flying objects that release projectiles |
| **Background** | Static image |
| **Sound** | Simple effects for jumps, hits, and wins |

---

## ⚙️ Tech Stack

- **Language:** C++  
- **Graphics Library:** [raylib](https://www.raylib.com/)  
- **Build System:** Makefile  

---

## 🧱 Build and Run

### Run the game:
```bash
make && ./game



