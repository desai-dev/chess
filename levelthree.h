#ifndef __LEVELTHREE_H__
#define __LEVELTHREE_H__
#include "abstractcomputer.h"

class LevelThree : public AbstractComputer {

  public:
    void nextMove() const override;
    ~LevelThree() = default;


};





#endif