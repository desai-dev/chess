#ifndef __KING_H__
#define __KING_H__
#include "piece.h"
#include <utility>

class King : public Piece {
  public: 
    King(Colour colour);
    bool isValid(int row, int col) override;

};



#endif

