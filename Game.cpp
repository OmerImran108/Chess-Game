#include "Game.h"
#include <iostream>
using namespace std;

// =================== NOTATION HELPERS ===================

Position parse(string s) {
    int r = 8 - (s[1] - '0');
    int c = s[0] - 'a';
    return Position(r, c);
}

string toNotation(Position p) {
    string s = "";
    s += char('a' + p.c);
    s += char('0' + (8 - p.r));
    return s;
}

// =================== GAME ===================

Game::Game() {
    turn = WHITE;
    board.setupPieces();
}

void Game::printHelp() {
    cout << endl << "Commands:" << endl;
    cout << "  e2 e4     : move" << endl;
    cout << "  moves e2  : show legal moves for piece" << endl;
    cout << "  quit      : exit game" << endl;
    cout << "  help      : show commands" << endl << endl;
}

void Game::switchTurn() {
    turn = (turn == WHITE) ? BLACK : WHITE;
}

void Game::handleMovesCommand(const string &square) {
    Position f = parse(square);
    Piece *p = board.get(f);

    if (p == nullptr || p->getColor() != turn) {
        cout << "No valid piece at " << square << endl;
        return;
    }

    cout << "Legal moves for " << p->symbol() << " at " << square << ": ";
    bool found = false;

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            Position t(r, c);
            if (p->canMove(f, t, board)) {
                cout << toNotation(t) << " ";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "(none)";
    }
    cout << endl;
}

void Game::handleMoveCommand(const string &fromStr, const string &toStr) {
    Position f = parse(fromStr);
    Position t = parse(toStr);
    Piece *p = board.get(f);

    if (p == nullptr || p->getColor() != turn || !p->canMove(f, t, board)) {
        cout << "Invalid move" << endl;
        return;
    }

    board.move(f, t);
    switchTurn();
}

void Game::run() {
    string a, b;

    while (true) {
        board.draw();
        printHelp();

        cout << ((turn == WHITE) ? "White" : "Black") << " move: ";
        cin >> a;

        if (a == "quit") {
            break;
        }

        if (a == "help") {
            continue;
        }

        if (a == "moves") {
            cin >> b;
            handleMovesCommand(b);
            continue;
        }

        // Regular move: read second square
        cin >> b;
        handleMoveCommand(a, b);
    }
}
