#ifndef __EMPTY_H__
#define __EMPTY_H__
#include "piece.h"
#include <utility>

class Empty : public Piece {

  public: 
    Empty(Colour colour);
    bool isValid(int row, int col) override;


};




#endif

