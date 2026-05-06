#include "Board.h"
#include <iostream>
using namespace std;

// =================== BOARD ===================

Board::Board() {
    // Initialize all cells to nullptr
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            grid[r][c] = nullptr;
        }
    }
}

Piece *Board::get(Position p) {
    if (p.r < 0 || p.r > 7 || p.c < 0 || p.c > 7) {
        return nullptr;
    }
    return grid[p.r][p.c];
}

void Board::set(Position p, Piece *pc) {
    grid[p.r][p.c] = pc;
}

void Board::move(Position f, Position t) {
    if (grid[t.r][t.c] != nullptr) {
        delete grid[t.r][t.c];  // Delete captured piece
    }
    grid[t.r][t.c] = grid[f.r][f.c];
    grid[f.r][f.c] = nullptr;
}

void Board::draw() {
    cout << endl << "  a b c d e f g h" << endl;

    for (int r = 0; r < 8; r++) {
        cout << 8 - r << " ";
        for (int c = 0; c < 8; c++) {
            if (grid[r][c] != nullptr) {
                cout << grid[r][c]->symbol() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << 8 - r << endl;
    }

    cout << "  a b c d e f g h" << endl;
}

void Board::setupPieces() {
    // White pawns on row 6, Black pawns on row 1
    for (int i = 0; i < 8; i++) {
        set({6, i}, new Pawn(WHITE));
        set({1, i}, new Pawn(BLACK));
    }

    // Rooks
    set({7, 0}, new Rook(WHITE));
    set({7, 7}, new Rook(WHITE));
    set({0, 0}, new Rook(BLACK));
    set({0, 7}, new Rook(BLACK));

    // Knights
    set({7, 1}, new Knight(WHITE));
    set({7, 6}, new Knight(WHITE));
    set({0, 1}, new Knight(BLACK));
    set({0, 6}, new Knight(BLACK));

    // Bishops
    set({7, 2}, new Bishop(WHITE));
    set({7, 5}, new Bishop(WHITE));
    set({0, 2}, new Bishop(BLACK));
    set({0, 5}, new Bishop(BLACK));

    // Queens
    set({7, 3}, new Queen(WHITE));
    set({0, 3}, new Queen(BLACK));

    // Kings
    set({7, 4}, new King(WHITE));
    set({0, 4}, new King(BLACK));
}
