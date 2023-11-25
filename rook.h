#ifndef __ROOK_H__
#define __ROOK_H__
#include "piece.h"
#include <utility>

class Rook : public Piece {

  public: 
    Rook(Colour colour);
    bool isValid(int row, int col) override;


};



#endif

