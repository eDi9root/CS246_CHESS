#include "TextDisplay.h"

#include <iostream>
#include <string>
using namespace std;

TextDisplay::TextDisplay(Board *sub) : subject{sub} { subject->attach(this); }

void TextDisplay::notify() {
    for (int i = 8; i > 0; --i) {
        cout << i << " ";
        for (int j = 8; j > 0; --j) {
            cout << Tochar(subject->getTile(i,j));
        }
        cout << "\n";
    }
    cout << "  abcdefgh\n";
}


string TextDisplay::Tochar(Tile *t) {
    Piece *p = t->getPiece();
    return p->printpiece();
}

TextDisplay::~TextDisplay() { subject->detach(this); }
