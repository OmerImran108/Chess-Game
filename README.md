1. Introduction
This project implements a simplified, fully playable chess game using the C++ programming language.
The primary aim of the project is to apply and demonstrate core Object-Oriented Programming (OOP) principles, including:
•	Abstraction
•	Encapsulation
•	Inheritance
•	Polymorphism
The game runs in the console and allows two human players to move pieces by typing commands such as “e2 e4”.
The program validates moves, updates the board, and displays the chessboard using text graphics.
________________________________________
2. Features of the Program
2.1 Visual Chessboard
•	The game displays an 8×8 chessboard using ASCII characters.
•	White pieces are shown using uppercase letters and black pieces using lowercase letters.
•	Empty squares appear as dots.
2.2 Movement and Rules
All major chess pieces are supported:
•	Pawns
•	Rooks
•	Knights
•	Bishops
•	Queens
•	Kings
Each piece follows its legal movement rules. The program checks:
•	Whether a move is allowed for that piece
•	Whether the path is clear (for non-knight pieces)
•	Whether the destination square contains a friendly or enemy piece
•	Whether captures are allowed
Invalid moves are rejected.
2.3 Commands
The player can enter different types of commands:
•	Move a piece (for example: “e2 e4”)
•	Ask for all legal moves from a given square (“moves e2”)
•	Request help (“help”)
•	Exit the program (“quit”)
2.4 Turn System
•	White always moves first.
•	Turns alternate automatically between White and Black players.
________________________________________
3. Object-Oriented Design
This project is a strong example of OOP design. The key structural elements are described below.
3.1 Base Class: Piece
•	Represents a general chess piece.
•	Contains data for color (white or black).
•	Declares virtual methods that subclasses override, including a method for determining whether a move is legal and one that returns the symbol of the piece.
3.2 Derived Classes
Six classes inherit from the base piece class, one for each type of chess piece:
•	Pawn
•	Rook
•	Knight
•	Bishop
•	Queen
•	King
Each class overrides the movement-checking method and implements the specific rules for how that piece moves.
3.3 Board Class
•	Responsible for maintaining the 8×8 grid.
•	Stores pointers to pieces.
•	Provides functions to access a square, place a piece, move a piece, capture a piece, and draw the board.
•	Includes safety checks for positions outside the board.
3.4 Position Structure
•	Represents a board coordinate using row and column numbers.
•	Used throughout the program to simplify movement calculations.
3.5 Polymorphism
When the board needs to check if a move is legal, it calls the piece’s movement method.
Because this method is virtual, the correct version (pawn, rook, knight, etc.) is selected automatically.
________________________________________
4. Input Parsing and Notation
The game uses standard chess notation for player input:
•	Letters (a–h) represent columns.
•	Numbers (1–8) represent rows.
Internally, this notation is converted into numerical row and column indices.
When listing legal moves, the game converts these coordinates back into user-friendly notation.
________________________________________
5. Algorithms and Movement Logic
5.1 Pawn Movement
•	Moves forward one square.
•	May move two squares on its first move if the path is clear.
•	Captures diagonally forward.
5.2 Rook Movement
•	Moves horizontally or vertically any number of squares.
•	Cannot jump over pieces.
5.3 Knight Movement
•	Moves in an “L” shape (two squares in one direction, one in another).
•	Can jump over pieces.
5.4 Bishop Movement
•	Moves diagonally any number of squares.
•	Path must be clear.
5.5 Queen Movement
•	Combines rook and bishop movement.
•	May move horizontally, vertically, or diagonally.
5.6 King Movement
•	Moves one square in any direction.
•	Capture rules apply as normal.
5.7 Absolute Value Calculations
Distance between squares is calculated using simple absolute value operations.
This is used heavily for pieces such as knights, bishops, and kings to determine legal move distances.
________________________________________
6. Memory Management
•	Pieces are created dynamically.
•	When a piece is captured, it is deleted to prevent memory leaks.
•	The overall design ensures that pieces are removed from the board when no longer needed.
________________________________________
7. Limitations of the Current Version
The program supports the core movement rules but does not yet include:
•	Check or checkmate detection
•	Castling
•	En passant
•	Pawn promotion
•	Game-ending conditions (stalemate, resignation, etc.)
•	Artificial intelligence opponent
These features could be added in future development.
________________________________________
8. Strengths of the Project
•	Clean object-oriented structure
•	Easy-to-read and maintain code
•	Clear demonstration of inheritance and polymorphism
•	Functional text-based chess system
•	Good use of dynamic memory, enums, and data structures
•	Provides a strong base for expanding into a full chess engine
________________________________________
9. Possible Improvements
Suggested upgrades include:
1.	Implementing check and checkmate detection
2.	Adding full chess rules such as castling and en passant
3.	Allowing pawn promotion
4.	Replacing raw pointers with smart pointers for safety
5.	Creating a GUI version (SDL, SFML, etc.)
6.	Adding an AI opponent using algorithms like Minimax
________________________________________
10. Conclusion
This project successfully implements a playable chess game using C++.
It serves as an excellent demonstration of object-oriented programming principles, accurate game logic, and interactive command-line design.
While simplified, the program forms a strong foundation that can be extended into a complete chess engine with additional development.


