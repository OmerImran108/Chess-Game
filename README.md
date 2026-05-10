    Chess Game in C++
A console-based two-player chess game built in C++ using Object-Oriented Programming principles.
    About
This project was developed as a semester project for the OOP Lab at FAST-NU CFD Campus. It implements a fully playable text-based chess game where two players take turns entering moves via the console.
    Features
	•	8×8 chessboard with ASCII display
	•	All 6 chess pieces with correct movement rules
	•	Move validation and capture logic
	•	Legal move listing (moves e2)
	•	Alternating turn system (White moves first)
    How to Play
e2 e4       → move piece
moves e2    → show legal moves
help        → show commands
quit        → exit game
    OOP Concepts Used
	•	Inheritance — Pawn, Rook, Knight, Bishop, Queen, King all inherit from base Piece class
	•	Polymorphism — Virtual functions for move validation
	•	Encapsulation — Private data members in all classes
	•	Composition — Board class contains Piece objects
    Project Structure
Piece.h / Piece.cpp --> Base class and all derived piece classes
Board.h / Board.cpp --> 8x8 grid management
Game.h / Game.cpp --> Game loop and turn system
Position.h --> Row/column coordinate structure
main.cpp -->  Entry point​​​​​​​​​​​​​​​​
    Contributors
	•	OmerImran
	•	Haroon
    •   Ahsan