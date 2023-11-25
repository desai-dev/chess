#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include "piece.h"
#include "textdisplay.h"

// enum class Colour { Black, White, None };
// enum class PType { Knight, Bishop, Rook, King, Queen, Pawn, Empty };

class Board {
    std::vector<std::vector<Piece*>> theBoard;
    const int gridSize = 8;
    TextDisplay *td;

    public:
        Board();
        // makes a move to the piece at given row and coloumn; makes sure piece is of given colour
        void makeMove(int row, int col, Colour c);
        // initializes board to a standard chess board
        void init();
        // sets piece at given row and coloumn to given piece type
        void set(int row, int col, PType p);
        // determines if a player has won
        bool isWon();
};

#endif