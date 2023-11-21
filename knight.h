#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "piece.h"
#include <utility>

class Knight : public Piece {

  public: 
    std::pair<int, int>getLocation() override;
    Colour getColour() override;
    bool isValid(int row, int col) override;
    PType getType() override;


};



#endif

