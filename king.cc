#include "king.h"
#include "board.h"

using namespace std;

King::King(Colour colour) : Piece{colour, PType::King} {};

bool King::isMoveValid(int row, int col, Board &b) {
    // vector<std::vector<Piece*>> theBoard = b.getBoard();
    // // initalize current row and column
    // int currentrow = this->getLocation().first;
    // int currentcol = this->getLocation().second;

    // // make sure move is located within board
    // if (row > 7 || col > 7 || row < 0 || col < 0){
    //     return false;
    // }
    // // make sure new location is one square away from current location
    // if (row - currentrow > 1 || row - currentrow < -1 || col - currentcol > 1 || col - currentcol < -1){
    //     return false;
    // }
    // // if its a castling move, check if it is valid or not

    // // make sure king does not move into piece of same colour
    // if (theBoard[row][col]->getColour() == this->getColour()) {
    //     return false;
    // }

    // // make sure king does not move into check (including the case that the king captures into a check)
    // for(int i = 0; i < b.getGridSize(); i++) {
    //     for(int j = 0; j < b.getGridSize(); j++) {
    //         // if a piece of the opposite colour can move to where the king wants to move, then the move is invalid
    //         if (!theBoard[i][j]->isEmpty() && (theBoard[i][j]->getColour() != this->getColour()) && theBoard[i][j]->isMoveValid(row, col, b)) {
    //             return false;
    //         }
    //     }
    // }


    // the move is valid if none of the above conditions are true
    return false;
}

King::~King() {}
