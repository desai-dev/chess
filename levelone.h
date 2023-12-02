#ifndef __LEVELONE_H__
#define __LEVELONE_H__
#include "abstractcomputer.h"
#include "board.h"
#include "piece.h"
#include <vector>

class LevelOne : public AbstractComputer {

  public:
    void nextMove(Colour c, Board &b) const override;
    ~LevelOne() = default;


};




#endif