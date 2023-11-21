#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include "observer.h"
#include "piece.h"

class TextDisplay: public Observer {
    public:
        TextDisplay(int n);

        void notify(Piece &c) override;

        ~TextDisplay();
};

#endif
