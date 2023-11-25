#include <vector>
#include "board.h"
#include "king.h"
#include "empty.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "pawn.h"
#include "knight.h"

using namespace std;

Board::Board() : theBoard{vector<vector<Piece*>>(8, vector<Piece*>(8))}, td{nullptr} {}

void Board::makeMove(int row, int col, Colour c) {
    return;
};

void Board::init() {
    td = new TextDisplay{};

    // set empty squares
    for (int i = 2; i < gridSize - 2; i++) {
        for (int j = 0; j < gridSize; j++) {
            theBoard[i][j] = new Empty(Colour::None);
        }
    }

    // set the white pieces
    theBoard[0][0] = new Rook(Colour::White);
    theBoard[0][1] = new Knight(Colour::White);
    theBoard[0][2] = new Bishop(Colour::White);
    theBoard[0][3] = new Queen(Colour::White);
    theBoard[0][4] = new King(Colour::White);
    theBoard[0][5] = new Bishop(Colour::White);
    theBoard[0][6] = new Knight(Colour::White);
    theBoard[0][7] = new Rook(Colour::White);

    for (int i = 0; i < gridSize; i++) {
        theBoard[1][i] = new Pawn(Colour::White);
    }

    // set the black pieces
    theBoard[7][0] = new Rook(Colour::Black);
    theBoard[7][1] = new Knight(Colour::Black);
    theBoard[7][2] = new Bishop(Colour::Black);
    theBoard[7][3] = new Queen(Colour::Black);
    theBoard[7][4] = new King(Colour::Black);
    theBoard[7][5] = new Bishop(Colour::Black);
    theBoard[7][6] = new Knight(Colour::Black);
    theBoard[7][7] = new Rook(Colour::Black);

    for (int i = 0; i < gridSize; i++) {
        theBoard[6][i] = new Pawn(Colour::Black);
    }

    // attatch observers and set location of pieces
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            theBoard[i][j]->setLocation(i, j);
            theBoard[i][j]->attach(td);
        }
    }
};

void Board::set(int row, int col, PType p) {
    return; // CHANGE LATER
}

bool Board::isWon() {
    return true; // CHANGE LATER
};