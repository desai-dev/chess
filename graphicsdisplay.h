#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__

#include "observer.h"
#include "piece.h"
#include "window.h"

class GraphicsDisplay: public Observer {
    Xwindow &win;
    const int gridSize = 560;
    const int cellWidth = 70;
    const int numCells = 8;

    public:
        GraphicsDisplay(Xwindow &w);

        void notify(Piece &p) override;

        ~GraphicsDisplay();
};

#endif