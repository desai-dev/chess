#ifndef __BOARD_H__
#define __BOARD_H__

enum class Colour { Black, White, None };
enum class PType { Knight, Bishop, Rook, King, Queen, Pawn, Empty };

class Board {
    public:
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