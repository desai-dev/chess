#include "knight.h"

Knight::Knight(Colour colour) : Piece{colour, PType::Knight} {};

bool Knight::isValid(int row, int col) {
    return true; // CHANGE LATER
}