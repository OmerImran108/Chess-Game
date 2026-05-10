#pragma once

#include "Position.h"

// Forward declaration
class Board;

// =================== PIECE BASE ===================

class Piece {
protected:
    Color color;

public:
    Piece(Color c);
    virtual ~Piece() {}

    Color getColor();

    virtual char symbol() = 0;
    virtual bool canMove(Position from, Position to, Board &board) = 0;
};

// =================== PAWN ===================

class Pawn : public Piece {
public:
    Pawn(Color c);
    char symbol() override;
    bool canMove(Position from, Position to, Board &board) override;
};

// =================== ROOK ===================

class Rook : public Piece {
public:
    Rook(Color c);
    char symbol() override;
    bool canMove(Position from, Position to, Board &board) override;
};

// =================== KNIGHT ===================

class Knight : public Piece {
public:
    Knight(Color c);
    char symbol() override;
    bool canMove(Position from, Position to, Board &board) override;
};

// =================== BISHOP ===================

class Bishop : public Piece {
public:
    Bishop(Color c);
    char symbol() override;
    bool canMove(Position from, Position to, Board &board) override;
};

// =================== QUEEN ===================

class Queen : public Piece {
public:
    Queen(Color c);
    char symbol() override;
    bool canMove(Position from, Position to, Board &board) override;
};

// =================== KING ===================

class King : public Piece {
public:
    King(Color c);
    char symbol() override;
    bool canMove(Position from, Position to, Board &board) override;
};

// =================== HELPER ===================

int absVal(int x);
