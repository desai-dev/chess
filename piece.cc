#include "piece.h"
#include "board.h"

Piece::Piece() : observers{}, location{-1, -1}, colour{Colour::None}, type{PType::Empty} {};

Piece::Piece(Colour colour, PType type) : observers{}, location{-1, -1}, colour{colour}, type{type} {};

void Piece::notifyObservers() {
    // call the notify method for every observer
    for (Observer* o : observers) {
        o->notify(*this);
    }
}

void Piece::attach(Observer *o) {
  observers.emplace_back(o);
}

bool Piece::isEmpty() {
    return (type == PType::Empty) ? true : false;
}

std::pair<int, int> Piece::getLocation() {
    return location;
}

Colour Piece::getColour() {
    return colour;
}

PType Piece::getType() {
    return type;
}

void Piece::setLocation(int row, int col) {
    location.first = row;
    location.second = col;
}

Piece::~Piece() { }