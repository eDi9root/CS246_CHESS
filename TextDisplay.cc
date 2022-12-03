#include "TextDisplay.h"

#include <iostream>
#include <string>
using namespace std;

TextDisplay::TextDisplay(Board *sub) : subject{sub} { subject->attach(this); }

void TextDisplay::notify() {
    int x = 0;
    for (int i = 8; i > 0; --i) {
        cout << i << " ";
        for (int j = 0; j < 8; ++j) {
            if (Tochar(subject->getPiece(j, x)) == " " && (x - j) % 2 != 0) {
                cout << "_";
            } else if (Tochar(subject->getPiece(j, x)) == " " &&
                       (x - j) % 2 == 0) {
                cout << " ";
            } else {
                cout << Tochar(subject->getPiece(j, x));
            }
        }
        x++;
        cout << "\n";
    }
    cout << "\n  abcdefgh\n";
}

string TextDisplay::Tochar(Piece *p) {
    if (p == NULL) {
        return " ";
    } else {
        if (p->getColor() == Piece::white) {
            switch (p->pid) {
                case Piece::King:
                    return "K";
                case Piece::Queen:
                    return "Q";
                case Piece::Bishop:
                    return "B";
                case Piece::Knight:
                    return "N";
                case Piece::Rook:
                    return "R";
                case Piece::Pawn:
                    return "P";
                default:
                    return 0;
            }
        } else {
            switch (p->pid) {
                case Piece::King:
                    return "k";
                case Piece::Queen:
                    return "q";
                case Piece::Bishop:
                    return "b";
                case Piece::Knight:
                    return "n";
                case Piece::Rook:
                    return "r";
                case Piece::Pawn:
                    return "p";
                default:
                    return 0;
            }
        }
    }
    return 0;
}

TextDisplay::~TextDisplay() { subject->detach(this); }
