#include "king.h"

King::King(Colour colour) : Piece{colour, PType::King} {};

bool King::isMoveValid(int row, int col) {
    return true; // CHANGE LATER
}

King::~King() {}