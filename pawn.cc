#include "pawn.h"

Pawn::Pawn(Colour colour) : Piece{colour, PType::Pawn} {};

bool Pawn::isMoveValid(int row, int col) {
    return true; // CHANGE LATER
}

Pawn::~Pawn() {}
