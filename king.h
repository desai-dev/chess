#ifndef __KING_H__
#define __KING_H__
#include "piece.h"
#include <utility>

class King : public Piece {
  public: 
    King(Colour colour);
    // determines if move made on king is valid
    bool isMoveValid(int row, int col) override;
    ~King() override;
};



#endif

