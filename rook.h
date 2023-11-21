#ifndef __ROOK_H__
#define __ROOK_H__
#include "piece.h"
#include <utility>

class Rook : public Piece {

  public: 
    std::pair<int, int>getLocation() override;
    Colour getColour() override;
    bool isValid(int row, int col) override;
    PType getType() override;


};



#endif

