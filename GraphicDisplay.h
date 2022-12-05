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
    int width, height;

   public:
    GraphicDisplay(Board *sub);
    ~GraphicDisplay();
    void notify() override;
};

#endif
