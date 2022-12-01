#include "TextDisplay.h"

#include <iostream>
#include <string>
using namespace std;

TextDisplay::TextDisplay(Board *sub) : subject{sub} { subject->attach(this); }

void TextDisplay::notify() {
    for (int i = 8; i > 0; --i) {
        cout << i << " ";
        for (int j = 8; j > 0; --j) {
            cout << Tochar(*subject->getTile(i, j));
        }
        cout << "\n";
    }
    cout << "  abcdefgh\n";
}

char TextDisplay::Tochar(Tile &t) {
    Piece *p = t.getPiece();
    switch (p->pid) {
        case 0:
            return 'K';
        case 1:
            return 'Q';
        case 2:
            return 'B';
        case 3:
            return 'K';
        case 4:
            return 'R';
        case 5:
            return 'P';
    }
    return '_';
}

TextDisplay::~TextDisplay() { subject->detach(this); }
