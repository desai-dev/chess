#include "king.h"

King::King(Colour colour) : Piece{colour, PType::King} {};

bool King::isValid(int row, int col) {
    return true; // CHANGE LATER
}