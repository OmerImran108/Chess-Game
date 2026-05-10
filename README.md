# Chess Game in C++

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Course](https://img.shields.io/badge/Course-OOP%20Lab-orange)
![Campus](https://img.shields.io/badge/Campus-FAST--NUCES%20CFD-darkgreen)
![Mode](https://img.shields.io/badge/Mode-Two%20Player-purple)

> A console-based chess game implementing real chess rules using core OOP principles in C++.

---

## 👨‍💻 Developers

| Member | GitHub | Contribution |
|--------|--------|--------------|
| Omer Imran | OmerImran108 | Board class & game loop |
| Haroon | Haroon784 | Piece hierarchy & move logic |
| Ahsan | Ahsan1 | Position structure & testing |

---

## 🕹️ Gameplay

Two players take turns entering moves in standard chess notation:

| Command | Action |
|---------|--------|
| `e2 e4` | Move piece from e2 to e4 |
| `moves e2` | List all legal moves for piece at e2 |
| `help` | Show available commands |
| `quit` | Exit the game |


White always moves first. Invalid moves are automatically rejected.

---

## ⚙️ How It Works

Each chess piece is its own class inheriting from a common `Piece` base class. The `Board` class manages the 8x8 grid and handles move execution and rendering. Movement rules are enforced through virtual functions — when a move is attempted, the correct piece logic runs automatically via polymorphism.

---

## 🗂️ Files

| File | Description |
|------|-------------|
| `Piece.h / Piece.cpp` | Base class and all 6 derived piece classes |
| `Board.h / Board.cpp` | 8×8 grid, move execution, board rendering |
| `Game.h / Game.cpp` | Game loop, turn system, input handling |
| `Position.h` | Coordinate structure for board positions |
| `main.cpp` | Program entry point |


---

## 📐 OOP Summary

- **Inheritance** — 6 piece classes derived from one base
- **Polymorphism** — virtual `canMove()` resolves at runtime
- **Encapsulation** — internal data hidden behind public methods
- **Composition** — Board owns and manages all Piece objects

