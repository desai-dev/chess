#ifndef __LEVELTWO_H__
#define __LEVELTWO_H__
#include "abstractcomputer.h"

class LevelTwo : public AbstractComputer {

  public:
    void nextMove() const override;
    ~LevelTwo() = default;


};





#endif