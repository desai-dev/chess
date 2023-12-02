#include <iostream>
#include "graphicsdisplay.h"

using namespace std;

// ctor with refrence to Xwindow
GraphicsDisplay::GraphicsDisplay(Xwindow &w) : win{w} {
    for (int i = 0; i < numCells*cellWidth; i += cellWidth) {
        for (int j = 0; j < numCells*cellWidth; j += cellWidth) {
            if ((i / cellWidth + j / cellWidth) % 2 == 0) {
                win.fillRectangle(j, i, cellWidth, cellWidth, 0);
            } else {
                win.fillRectangle(j, i, cellWidth, cellWidth);
            }
        }
    }

    // draw white pawns
    for (int i = 0; i < numCells*cellWidth; i += cellWidth) {
        win.drawPawn(i, 420, 3);
    }
    // draw white pawns
    for (int i = 0; i < numCells*cellWidth; i += cellWidth) {
        win.drawPawn(i, 70, 2);
    }
    // draw white rooks
    win.drawRook(0, 490, 3);
    win.drawRook(490, 490, 3);

    // draw black rooks
    win.drawRook(0, 0, 2);
    win.drawRook(490, 0, 2);

    // draw white knights
    win.drawKnight(70, 490, 3);
    win.drawKnight(420, 490, 3);

    // draw black kights
    win.drawKnight(70, 0, 2);
    win.drawKnight(420, 0, 2);

    // draw white bishops
    win.drawBishop(140, 490, 3);
    win.drawBishop(350, 490, 3);
    
    // draw black bishops
    win.drawBishop(140, 0, 2);
    win.drawBishop(350, 0, 2);

    // draw white queen
    win.drawQueen(210, 490, 3);
    
    // draw black queen
    win.drawQueen(210, 0, 2);

    // draw white king
    win.drawKing(280, 490, 3);
    
    // draw black king
    win.drawKing(280, 0, 2);
}

// draw the piece at its new location
void GraphicsDisplay::notify(Piece &p) {
    // get location and type of piece
    pair<int, int> loc = p.getLocation();
    PType t = p.getType();

    // get colour of piece
    int colour = (p.getColour() == Colour::Black) ? 2 : 3;

    // update display based on the new location of the piece
    if (t == PType::Knight) {
        win.drawKnight(loc.first*cellWidth, loc.second*cellWidth, colour);
    } else if (t == PType::Bishop) {
        win.drawBishop(loc.first*cellWidth, loc.second*cellWidth, colour);
    } else if (t == PType::Rook) {
        win.drawRook(loc.first*cellWidth, loc.second*cellWidth, colour);
    } else if (t == PType::King) {
        win.drawKing(loc.first*cellWidth, loc.second*cellWidth, colour);
    } else if (t == PType::Queen) {
        win.drawQueen(loc.first*cellWidth, loc.second*cellWidth, colour);
    } else if (t == PType::Pawn) {
        win.drawPawn(loc.first*cellWidth, loc.second*cellWidth, colour);
    } else {
        if ((loc.first + loc.second) % 2 == 0) {
            // change colour for white tile
            colour = 0;
            win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, colour);
        } else {
            // change colour for black tile
            colour = 1;
            win.fillRectangle(loc.first*cellWidth, loc.second*cellWidth, cellWidth, cellWidth, colour);
        }
    }
};

GraphicsDisplay::~GraphicsDisplay() {};

