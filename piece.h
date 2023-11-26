#ifndef __PIECE_H__
#define __PIECE_H__
#include "observer.h"
#include <utility>
#include <vector>

// Forward declaration of Observer class
class Observer;

enum class Colour { Black, White, None };
enum class PType { Knight, Bishop, Rook, King, Queen, Pawn, Empty };

class Piece {
    protected:
        std::vector<Observer*> observers;
        std::pair<int, int> location;
        Colour colour;
        PType type;

    public:
        Piece();
        Piece(Colour colour, PType type);
        // Alert observers that there has been a change in state
        void notifyObservers();
        // Attach an observer to the piece
        void attach(Observer *o);

        // accessor and mutator funtions
        std::pair<int, int> getLocation();
        Colour getColour();
        PType getType();
        void setLocation(int row, int col);
        
        // virtual functions to be overridden
        virtual bool isMoveValid(int row, int col) = 0;
        virtual ~Piece() = 0;
};

#endif