# ♟️ Chess Game in C++

![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue)
![Course](https://img.shields.io/badge/Course-Object--Oriented%20Programming-orange)
![University](https://img.shields.io/badge/University-FAST--NUCES%20CFD-green)
![Type](https://img.shields.io/badge/Type-Console%20Based-lightgrey)

A fully playable two-player chess game built in C++ for the OOP Lab semester project at FAST-NUCES, CFD Campus. The game runs in the console and enforces real chess rules with move validation, turn management, and piece capture.

---

## 👥 Group Members

| Name | GitHub | Role |
|------|--------|------|
| Omer Imran | OmerImran108 | Board & Game Logic |
| Haroon | Haroon784 | Piece Classes & Move Validation |
| Ahsan | — | Position & Integration |

---

## ✅ Features

- 8×8 chessboard rendered in the console
- All 6 chess pieces with correct movement rules
- Move validation — illegal moves are rejected
- Piece capture with memory cleanup
- Legal move listing for any piece
- Alternating turn system — White moves first
- Simple command interface

---

## 🎮 Commands

| Command | Action |
|---------|--------|
| `e2 e4` | Move piece from e2 to e4 |
| `moves e2` | List all legal moves for piece at e2 |
| `help` | Show available commands |
| `quit` | Exit the game |

---

## 🧱 OOP Concepts

| Concept | How It's Used |
|---------|--------------|
| Inheritance | Pawn, Rook, Knight, Bishop, Queen, King all inherit from base `Piece` class |
| Polymorphism | Virtual `canMove()` called at runtime on base class pointers |
| Encapsulation | Private data members with controlled public access |
| Composition | `Board` class owns and manages all `Piece` objects |

---

## 📁 Project Structure

| File | Description |
|------|-------------|
| `Piece.h / Piece.cpp` | Base class and all 6 derived piece classes |
| `Board.h / Board.cpp` | 8×8 grid, move execution, board rendering |
| `Game.h / Game.cpp` | Game loop, turn system, input handling |
| `Position.h` | Coordinate structure for board positions |
| `main.cpp` | Program entry point |
