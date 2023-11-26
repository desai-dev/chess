#include "queen.h"

Queen::Queen(Colour colour) : Piece{colour, PType::Queen} {};

bool Queen::isMoveValid(int row, int col) {
    return true; // CHANGE LATER
}

Queen::~Queen() {}
