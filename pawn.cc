#include "pawn.h"

Pawn::Pawn(Colour colour) : Piece{colour, PType::Pawn} {};

bool Pawn::isValid(int row, int col) {
    return true; // CHANGE LATER
}