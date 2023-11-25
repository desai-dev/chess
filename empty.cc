#include "empty.h"

Empty::Empty(Colour colour) : Piece{colour, PType::Empty} {};

bool Empty::isValid(int row, int col) {
    return true; // CHANGE LATER
}