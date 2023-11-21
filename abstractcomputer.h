#ifndef __ABSTRACTCOMPUTER_H__
#define __ABSTRACTCOMPUTER_H__

// For Computer Bot
class AbstractComputer {

  public:
    // Virtual method for making the next move
    //   will call the make move function from board
    virtual void nextMove() const = 0;
    virtual ~AbstractComputer() = 0;


};




#endif
