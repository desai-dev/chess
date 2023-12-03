#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__
#include "abstractcomputer.h"
#include "board.h"
#include "piece.h"
#include <vector>
#include "empty.h"

class LevelTwo : public AbstractComputer {

  public:
    void nextMove(Colour c, Board &b, bool inCheck) const override;
    ~LevelTwo() = default;


};





#endif