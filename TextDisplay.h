#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H

#include <iostream>

#include "Board.h"
#include "observer.h"
using namespace std;

class TextDisplay : public Observer {
    Board *subject;

   public:
    void notify() override;
    string Tochar(Piece *p);
    TextDisplay(Board *sub);
    ~TextDisplay();
};

#endif
