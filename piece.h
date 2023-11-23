#ifndef __PIECE_H__
#define __PIECE_H__
#include "observer.h"
#include <utility>

// Forward declaration of Observer class
class Observer;

enum class Colour { Black, White, None };
enum class PType { Knight, Bishop, Rook, King, Queen, Pawn, Empty };

class Piece {
    public:
        // Alert observers that there has been a change in state
        void notifyObservers();
        // Attach an observer to the piece
        void attach(Observer *o);
        // Dettach an observer to the piece
        void dettach(Observer * o);

        virtual std::pair<int, int>getLocation() = 0;
        virtual Colour getColour() = 0;
        virtual bool isValid(int row, int col) = 0;
        virtual PType getType() = 0;
};

#endif