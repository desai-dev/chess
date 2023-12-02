#ifndef __LEVELTHREE_H__
#define __LEVELTHREE_H__
#include "abstractcomputer.h"
#include "board.h"
#include "piece.h"
#include <vector>

class LevelThree : public AbstractComputer {

  public:
    void nextMove(Colour c, Board &b) const override;
    ~LevelThree() = default;


};





#endif