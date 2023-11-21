#ifndef __PIECE_H__
#define __PIECE_H__
#include "observer.h"
#include <utility>

enum class Colour { Black, White };
enum class PType { Knight, Bishop, Rook, King, Queen, Pawn };

class Piece : public Observer {
    public:
        // Alert observors that there has been a change in state
        void notifyObservors();
        // Attach an observor to the piece
        void attach(Observer *o);
        // Dettach an observor to the piece
        void dettach(Observer * o);

        virtual std::pair<int, int>getLocation();
        virtual Colour getColour();
        virtual bool isValid(int row, int col);
        virtual PType getType();
};

#endif