#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__
#include "abstractcomputer.h"
#include "board.h"
#include "piece.h"
#include <vector>
#include "empty.h"

class LevelTwo : public AbstractComputer {

  public:
    void nextMove(Colour c, Board &b) const override;
    ~LevelTwo() = default;


};





#endif