#ifndef __BISHOP_H__
#define __BISHOP_H__
#include "piece.h"
#include <utility>

class Bishop : public Piece {

  public: 
    std::pair<int, int>getLocation() override;
    Colour getColour() override;
    bool isValid(int row, int col) override;
    PType getType() override;


};




#endif

