#ifndef __QUEEN_H__
#define __QUEEN_H__
#include "piece.h"
#include <utility>

class Queen : public Piece {

  public: 
    Queen(Colour colour);
    bool isValid(int row, int col) override;


};



#endif

