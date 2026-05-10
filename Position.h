#pragma once

// =================== COLOR ===================

enum Color { WHITE, BLACK };

// =================== POSITION ===================

struct Position {
    int r, c;

    Position(int r = 0, int c = 0) {
        this->r = r;
        this->c = c;
    }
};
