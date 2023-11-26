#include "bishop.h"

Bishop::Bishop(Colour colour) : Piece{colour, PType::Bishop} {};

bool Bishop::isMoveValid(int row, int col) {
    return true; // CHANGE LATER
}

Bishop::~Bishop() {}
