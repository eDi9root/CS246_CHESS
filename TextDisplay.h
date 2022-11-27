#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H

#include <iostream>
#include <string>
using namespace std;

class King: public Piece {
    char **Tdisplay;

public:
    void notify(char letter, int row, int col);
    TextDisplay();
    friend ostream &operator<<(ostream &out, const TextDisplay &t)
    ~TextDisplay();
};

#endif
