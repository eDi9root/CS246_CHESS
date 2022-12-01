#include "TextDisplay.h"

#include <iostream>
#include <string>
using namespace std;

TextDisplay::TextDisplay(Board *sub) : subject{sub} { subject->attach(this); }

void TextDisplay::notify() {
    for (int i = 8; i > 0; --i) {
        cout << i << " ";
        for (int j = 8; j > 0; --j) {
            cout << " ";
            //cout << Tochar(subject->getTile(i,j));
            //cout << subject->getTile(i,j);
            cout << subject->getTile(i,j)->getPiece();
        }
        cout << "\n";
    }
    cout << "  abcdefgh\n";
}


string TextDisplay::Tochar(Piece *p) {
    if (p == NULL) {
        return " ";
    } else {
        switch(p->pid) {
            case Piece::King:
            return "K";
            case Piece::Queen:
            return "Q";
            case Piece::Bishop:
            return "B";
            case Piece::Knight:
            return "K";
            case Piece::Rook:
            return "R";
            case Piece::Pawn:
            return "P";
            default:
            return 0;
        }
    }
    //Piece *p = t->getPiece();
    //return p->printpiece();
    return 0;
}


string TextDisplay::Tochar(Tile *p) {
    Piece *n = p->getPiece();
    if (n == 0) {
        return " ";
    } else {
        switch(n->pid) {
            case Piece::King:
            return "K";
            case Piece::Queen:
            return "Q";
            case Piece::Bishop:
            return "B";
            case Piece::Knight:
            return "K";
            case Piece::Rook:
            return "R";
            case Piece::Pawn:
            return "P";
            default:
            return 0;
        }
    }
    //Piece *p = t->getPiece();
    //return p->printpiece();
    return 0;
}

TextDisplay::~TextDisplay() { subject->detach(this); }
