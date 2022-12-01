#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H

#include <iostream>

#include "Board.h"
#include "Tile.h"
#include "observer.h"
using namespace std;

class TextDisplay : public Observer {
    Board *subject;
    // ostream &out = cout;

   public:
    void notify() override;
    char Tochar(Tile &t);
    TextDisplay(Board *sub);
    ~TextDisplay();
};

#endif
