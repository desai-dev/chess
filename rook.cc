#include "rook.h"

Rook::Rook(Colour colour) : Piece{colour, PType::Rook} {};

bool Rook::isMoveValid(int row, int col) {
    return true; // CHANGE LATER
}

Rook::~Rook() {}
