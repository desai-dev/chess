#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <vector>
#include <iostream>
#include "observer.h"
#include "piece.h"

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theDisplay;
    const int boardSize = 8;

    public:
        TextDisplay();

        void notify(Piece &p) override;

        ~TextDisplay();

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
