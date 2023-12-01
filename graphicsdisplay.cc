#include <iostream>
#include "graphicsdisplay.h"

using namespace std;

// ctor with refrence to Xwindow
GraphicsDisplay::GraphicsDisplay(Xwindow &w) : win{w} {
    for (int i = 0; i < numCells*cellWidth; i += cellWidth) {
        for (int j = 0; j < numCells*cellWidth; j += cellWidth) {
            win.fillRectangle(j, i, cellWidth, cellWidth);
        }
    }
}

// draw a black rectangle if new state is off, otherwise draw a white rectangle
void GraphicsDisplay::notify(Piece &p) {
    // get location and type of piece
    pair<int, int> loc = p.getLocation();
    PType t = p.getType();

    // update display based on the new location of the piece
    if (t == PType::Knight) {
        win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, 0);
    } else if (t == PType::Bishop) {
        win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, 0);
    } else if (t == PType::Rook) {
        win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, 0);
    } else if (t == PType::King) {
        win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, 0);
    } else if (t == PType::Queen) {
        win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, 0);
    } else if (t == PType::Pawn) {
        win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, 0);
    } else {
        if ((loc.first + loc.second) % 2 == 0) {
            win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, 0);
        } else {
            win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth);
        }
    }
};

GraphicsDisplay::~GraphicsDisplay() {};

