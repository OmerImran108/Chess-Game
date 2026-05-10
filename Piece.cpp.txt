#include "Piece.h"
#include "Board.h"

// =================== HELPER ===================

int absVal(int x) {
    return (x < 0) ? -x : x;
}

// =================== PIECE BASE ===================

Piece::Piece(Color c) {
    color = c;
}

Color Piece::getColor() {
    return color;
}

// =================== PAWN ===================

Pawn::Pawn(Color c) : Piece(c) {}

char Pawn::symbol() {
    return (color == WHITE) ? 'P' : 'p';
}

bool Pawn::canMove(Position f, Position t, Board &b) {
    int d = (color == WHITE) ? -1 : 1;

    // Normal one-square move
    if (f.c == t.c && b.get(t) == nullptr && t.r == f.r + d) {
        return true;
    }

    // Double move from starting row
    if (f.c == t.c && b.get(t) == nullptr) {
        if (color == WHITE && f.r == 6 && t.r == 4 && b.get({5, f.c}) == nullptr) {
            return true;
        }
        if (color == BLACK && f.r == 1 && t.r == 3 && b.get({2, f.c}) == nullptr) {
            return true;
        }
    }

    // Diagonal capture
    if (absVal(f.c - t.c) == 1 && t.r == f.r + d) {
        Piece *p = b.get(t);
        if (p != nullptr && p->getColor() != color) {
            return true;
        }
    }

    return false;
}

// =================== ROOK ===================

Rook::Rook(Color c) : Piece(c) {}

char Rook::symbol() {
    return (color == WHITE) ? 'R' : 'r';
}

bool Rook::canMove(Position f, Position t, Board &b) {
    // Must move along a row or column
    if (f.r != t.r && f.c != t.c) {
        return false;
    }

    int dr = 0, dc = 0;
    if (t.r > f.r) dr = 1;
    else if (t.r < f.r) dr = -1;
    if (t.c > f.c) dc = 1;
    else if (t.c < f.c) dc = -1;

    // Check for pieces blocking the path
    Position p(f.r + dr, f.c + dc);
    while (p.r != t.r || p.c != t.c) {
        if (b.get(p) != nullptr) {
            return false;
        }
        p.r += dr;
        p.c += dc;
    }

    Piece *q = b.get(t);
    return (q == nullptr || q->getColor() != color);
}

// =================== KNIGHT ===================

Knight::Knight(Color c) : Piece(c) {}

char Knight::symbol() {
    return (color == WHITE) ? 'N' : 'n';
}

bool Knight::canMove(Position f, Position t, Board &b) {
    int dr = absVal(f.r - t.r);
    int dc = absVal(f.c - t.c);

    if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) {
        return false;
    }

    Piece *p = b.get(t);
    return (p == nullptr || p->getColor() != color);
}

// =================== BISHOP ===================

Bishop::Bishop(Color c) : Piece(c) {}

char Bishop::symbol() {
    return (color == WHITE) ? 'B' : 'b';
}

bool Bishop::canMove(Position f, Position t, Board &b) {
    // Must move diagonally
    if (absVal(f.r - t.r) != absVal(f.c - t.c)) {
        return false;
    }

    int dr = (t.r > f.r) ? 1 : -1;
    int dc = (t.c > f.c) ? 1 : -1;

    // Check for pieces blocking the path
    Position p(f.r + dr, f.c + dc);
    while (p.r != t.r) {
        if (b.get(p) != nullptr) {
            return false;
        }
        p.r += dr;
        p.c += dc;
    }

    Piece *q = b.get(t);
    return (q == nullptr || q->getColor() != color);
}

// =================== QUEEN ===================

Queen::Queen(Color c) : Piece(c) {}

char Queen::symbol() {
    return (color == WHITE) ? 'Q' : 'q';
}

bool Queen::canMove(Position f, Position t, Board &b) {
    // Queen combines Rook and Bishop movement
    Rook r(color);
    Bishop bp(color);
    return r.canMove(f, t, b) || bp.canMove(f, t, b);
}

// =================== KING ===================

King::King(Color c) : Piece(c) {}

char King::symbol() {
    return (color == WHITE) ? 'K' : 'k';
}

bool King::canMove(Position f, Position t, Board &b) {
    if (absVal(f.r - t.r) <= 1 && absVal(f.c - t.c) <= 1) {
        Piece *p = b.get(t);
        return (p == nullptr || p->getColor() != color);
    }
    return false;
}
