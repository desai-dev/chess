#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include "piece.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "window.h"

class Board {
    std::vector<std::vector<Piece*>> theBoard;
    const int gridSize = 8;
    TextDisplay *td;
    GraphicsDisplay *gd;
    Xwindow win;

    public:
        Board();
        ~Board();
        // makes a move to the piece at given row and coloumn; makes sure piece is of given colour
        bool makeMove(int fromRow, int fromCol, int toRow, int toCol, Colour c);
        // initializes board to a standard chess board
        void init();
        // sets piece at given row and coloumn to given piece type
        void set(int row, int col, PType p, Colour c);
        // Checks if board is in a valid state or not for set
        bool checkValid() const;
        // determines if a player has won = 1, stalemate = 2, nothing = 0
        int getGameState(Colour c);
        // returns the 2D vector of Piece pointers
        std::vector<std::vector<Piece*>> getBoard();
        // returns gridsize
        int getGridSize();
        // Clears board (leaves 2 kings)
        void clear();

        friend std::ostream &operator<<(std::ostream &out, const Board &b);

};

#endif