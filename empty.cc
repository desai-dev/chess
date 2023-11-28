#include "empty.h"

Empty::Empty(Colour colour) : Piece{colour, PType::Empty} {};

bool Empty::isMoveValid(int row, int col) {
    return false; // Empty piece should never have a valid move
}

Empty::~Empty() {}
