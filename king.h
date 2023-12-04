#ifndef __KING_H__
#define __KING_H__
#include "piece.h"
#include <utility>

class King : public Piece {
  bool hasMoved = false;
  public: 
    King(Colour colour);
    // determines if move made on king is valid
    bool isMoveValid(int row, int col, Board &b) override;
    // determines if the king is in check or not
    bool IsInCheck(int row, int col, Board &b);
    // returns getHasMoved
    bool getHasMoved() const override;
    // sets getHasMoved
    void setHasMoved() override;

    ~King() override;
};



#endif

