#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__

#include "observer.h"
#include "piece.h"
// #include "window.h"

class GraphicsDisplay: public Observer {
    public:
        GraphicsDisplay(int n, Xwindow &w);

        void notify(Piece &p) override;

        ~GraphicsDisplay();
};

#endif