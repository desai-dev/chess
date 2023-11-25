#ifndef __PAWN_H__
#define __PAWN_H__
#include "piece.h"
#include <utility>

class Pawn : public Piece {

  public: 
    Pawn(Colour colour);
    bool isValid(int row, int col) override;


};



#endif

