#include "rook.h"

Rook::Rook(Colour colour) : Piece{colour, PType::Rook} {};

bool Rook::isValid(int row, int col) {
    return true; // CHANGE LATER
}