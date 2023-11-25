#ifndef __BISHOP_H__
#define __BISHOP_H__
#include "piece.h"
#include <utility>

class Bishop : public Piece {

  public: 
    Bishop(Colour colour);
    bool isValid(int row, int col) override;


};




#endif

