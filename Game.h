#pragma once

#include "Board.h"
#include "Position.h"
#include <string>
using namespace std;

// =================== NOTATION HELPERS ===================

Position parse(string s);
string toNotation(Position p);

// =================== GAME ===================

class Game {
private:
    Board board;
    Color turn;

    void handleMovesCommand(const string &square);
    void handleMoveCommand(const string &from, const string &to);
    void printHelp();
    void switchTurn();

public:
    Game();
    void run();  // Main game loop
};
