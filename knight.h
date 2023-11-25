#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "piece.h"
#include <utility>

class Knight : public Piece {

  public: 
    Knight(Colour colour);
    bool isValid(int row, int col) override;


};



#endif

