#ifndef GRAPHIC_DISPLAY_H
#define GRAPHIC_DISPLAY_H

#include <iostream>
#include <vector>

#include "Board.h"
#include "observer.h"
#include "window.h"

class GraphicDisplay : public Observer {
    Board *sub_gr;
    Xwindow window;

   public:
    GraphicDisplay(Board *sub);
    ~GraphicDisplay();
    string Tochar(Piece *p);
    void notify() override;
};

#endif
