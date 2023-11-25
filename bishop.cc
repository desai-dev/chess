#include "bishop.h"

Bishop::Bishop(Colour colour) : Piece{colour, PType::Bishop} {};

bool Bishop::isValid(int row, int col) {
    return true; // CHANGE LATER
}