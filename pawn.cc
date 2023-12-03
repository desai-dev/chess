#include "pawn.h"
#include "board.h"
#include "queen.h"

using namespace std;

Pawn::Pawn(Colour colour) : Piece{colour, PType::Pawn} {};

bool Pawn::isMoveValid(int row, int col, Board &b) {
    vector<std::vector<Piece*>> theBoard = b.getBoard();

    int defaultRow;
    if (this->getColour() == Colour::White) {
        defaultRow = 6;
    } else {
        defaultRow = 1;
    }

    // initalize current row and column
    int currentRow = this->getLocation().first;
    int currentCol = this->getLocation().second;

    // make sure pawn is moving
    if (row == currentRow && col == currentCol) {
        return false;
    }

    // make sure move is located within board
    int gridSize = b.getGridSize();
    if (row >= gridSize || col >= gridSize || row < 0 || col < 0) {
        return false;
    }

    // Determine the direction of movement based on the pawn's color
    int moveDirection;
    if (this->getColour() == Colour::White) {
        moveDirection = -1;
    } else {
        moveDirection = 1;
    }

    // Pawns can move forward by one square (default)
    if (row == currentRow + moveDirection && col == currentCol && theBoard[row][col]->isEmpty()) {
        return true;
    }

    // Pawns have the option to move forward by two squares on their first move
    if (currentRow == defaultRow && row == currentRow + (2 * moveDirection) && col == currentCol && theBoard[row][col]->isEmpty() 
        && theBoard[currentRow + moveDirection][col]->isEmpty()) {
        return true;
    }

    // Pawns capture diagonally
    if (row == currentRow + moveDirection && (col == currentCol + 1 || col == currentCol - 1) &&
        !theBoard[row][col]->isEmpty() && theBoard[row][col]->getColour() != this->getColour()) {
        return true;
    }

    // Pawns can capture with en passant
    if (row =)

    return false;
}

Pawn::~Pawn() {}
