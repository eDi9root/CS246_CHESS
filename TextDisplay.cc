#include <iostream>
#include <string>
#include "TextDisplay.h"
using namespace std;

void TextDisplay::notify(char letter, int row, int col) {
    Tdisplay[row][col] = letter;
}

TextDisplay::TextDisplay() {
    Tdisplay = new char *[8];
    for (int i = 0; i < 8; ++i) {
        Tdisplay[i] = new char[8];
    }
}

ostream &operator<<(ostream &out, const TextDisplay &t) {
    for (int row = 7; row >= 0; --row) {
        for (int col = 0; col < 8; ++col) {
            if (t.Tdisplay[row][col] == ' ') {
                if ((row % 2 == 0 && col % 2 == 0) || (row % 2 != 0 && col % 2 != 0)) {
                    out << "_";
                } else {
                    out << " ";
                }
            } else {
                out << t.Tdisplay[row][col];
            }
        }
        out << endl;
    }
    return out;
}

TextDisplay::~TextDisplay() {
    for (int i = 0; i < 8; ++i) {
        delete [] Tdisplay[i];
    }
    delete [] Tdisplay;
}
