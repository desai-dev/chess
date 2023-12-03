#ifndef __LEVELTHREE_H__
#define __LEVELTHREE_H__
#include "abstractcomputer.h"
#include "board.h"
#include "piece.h"
#include <vector>
#include "empty.h"

class LevelThree : public AbstractComputer {

  public:
    void nextMove(Colour c, Board &b, bool inCheck) const override;
    ~LevelThree() = default;


};





#endif
