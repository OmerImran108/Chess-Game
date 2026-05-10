# ♟ Chess Game in C++

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Course](https://img.shields.io/badge/Course-Object--Oriented%20Programming-orange)
![University](https://img.shields.io/badge/University-FAST--NUCES%20CFD-green)

A console-based two-player chess game built in C++ using Object-Oriented Programming principles. Developed as a semester project at FAST-NUCES, CFD Campus.

---

## 👥 Group Members

| Name | GitHub |
|------|--------|
| Omer Imran | OmerImran108 |
| Haroon | Haroon784 |
| Ahsan  |  Ahsan1   |

---

## 🎮 How to Play
e2 e4       → move piece
moves e2    → show legal moves
help        → show commands
quit        → exit game 


---

## 🧱 OOP Concepts Applied

**Inheritance**
Base class `Piece` is inherited by all six piece types — `Pawn`, `Rook`, `Knight`, `Bishop`, `Queen`, `King`.

**Polymorphism**
Virtual `canMove()` and `symbol()` functions are called at runtime on base class pointers.

**Encapsulation**
Private data members with public methods in all classes.

**Composition**
`Board` class contains `Piece` pointers in an 8x8 grid.

---

## 📁 File Structure

| File | Description |
|------|-------------|
| `Piece.h / Piece.cpp` | Base class and all 6 piece subclasses |
| `Board.h / Board.cpp` | 8x8 grid management |
| `Game.h / Game.cpp` | Game loop and turn system |
| `Position.h` | Row/column coordinate structure |
| `main.cpp` | Entry point |

---

## ⚠️ Limitations
- No checkmate or check detection
- No castling or en passant
- No pawn promotion







