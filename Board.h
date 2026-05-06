#pragma once

#include "Piece.h"
#include "Position.h"

// =================== BOARD ===================

class Board {
public:
    Piece *grid[8][8];

    Board();

    Piece *get(Position p);
    void set(Position p, Piece *pc);
    void move(Position from, Position to);
    void draw();

    void setupPieces();  // Places all pieces in starting positions
};
