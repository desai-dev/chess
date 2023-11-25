#include "queen.h"

Queen::Queen(Colour colour) : Piece{colour, PType::Queen} {};

bool Queen::isValid(int row, int col) {
    return true; // CHANGE LATER
}