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

void Board::makeMove(int fromRow, int fromCol, int toRow, int toCol, Colour c) {
    // if its a valid move, then make the move
    if (theBoard[fromRow][fromCol]->isMoveValid(toRow, toCol)) {
        // move piece to new position, and make old position empty
        delete theBoard[toRow][toCol];
        theBoard[toRow][toCol] = theBoard[fromRow][fromCol];
        theBoard[fromRow][fromCol] = new Empty(Colour::None);
        theBoard[fromRow][fromCol]->attach(td);

        // update locations
        theBoard[fromRow][fromCol]->setLocation(fromRow, fromCol);
        theBoard[toRow][toCol]->setLocation(toRow, toCol);

        // notify observers
        theBoard[fromRow][fromCol]->notifyObservers();
        theBoard[toRow][toCol]->notifyObservers();
    }
};

void Board::init() {
    // initialize members
    td = new TextDisplay{};

    // set empty squares
    for (int i = 2; i < gridSize - 2; i++) {
        for (int j = 0; j < gridSize; j++) {
            theBoard[i][j] = new Empty(Colour::None);
        }
    }

    // set the black pieces
    theBoard[0][0] = new Rook(Colour::Black);
    theBoard[0][1] = new Knight(Colour::Black);
    theBoard[0][2] = new Bishop(Colour::Black);
    theBoard[0][3] = new Queen(Colour::Black);
    theBoard[0][4] = new King(Colour::Black);
    theBoard[0][5] = new Bishop(Colour::Black);
    theBoard[0][6] = new Knight(Colour::Black);
    theBoard[0][7] = new Rook(Colour::Black);

    for (int i = 0; i < gridSize; i++) {
        theBoard[1][i] = new Pawn(Colour::Black);
    }

    // set the white pieces
    theBoard[7][0] = new Rook(Colour::White);
    theBoard[7][1] = new Knight(Colour::White);
    theBoard[7][2] = new Bishop(Colour::White);
    theBoard[7][3] = new Queen(Colour::White);
    theBoard[7][4] = new King(Colour::White);
    theBoard[7][5] = new Bishop(Colour::White);
    theBoard[7][6] = new Knight(Colour::White);
    theBoard[7][7] = new Rook(Colour::White);

    for (int i = 0; i < gridSize; i++) {
        theBoard[6][i] = new Pawn(Colour::White);
    }

    // attatch observers and set location of pieces
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            theBoard[i][j]->setLocation(i, j);
            theBoard[i][j]->attach(td);
        }
    }
};

void Board::set(int row, int col, PType p, Colour c) {
    // Delete old piece at [row][col]
    delete theBoard[row][col];    
    
    // Create new piece at [row][col]
    switch (p) {
        case PType::King:
            theBoard[row][col] = new King(c);
            break;
        case PType::Queen:
            theBoard[row][col] = new Queen(c);
            break;
        case PType::Rook:
            theBoard[row][col] = new Rook(c);
            break;
        case PType::Bishop:
            theBoard[row][col] = new Bishop(c);
            break;
        case PType::Knight:
            theBoard[row][col] = new Knight(c);
            break;
        case PType::Pawn:
            theBoard[row][col] = new Pawn(c);
            break;
        default:
            theBoard[row][col] = new Empty(c);
            break;
    }

    // Add observer, update location, notify observer
        theBoard[row][col]->attach(td);
        theBoard[row][col]->setLocation(row, col);
        theBoard[row][col]->notifyObservers();
}

bool Board::isWon() {
    return true; // CHANGE LATER
};