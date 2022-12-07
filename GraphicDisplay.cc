#include "GraphicDisplay.h"

#include <iostream>
#include <string>

#include "Board.h"
#include "Piece.h"
#include "window.h"

using namespace std;

GraphicDisplay::GraphicDisplay(Board *sub) : sub_gr{sub}, window{500, 500} {
    sub_gr->attach(this);
    // draw board
    for (int i = 8; i > 0; --i) {
        window.drawBigString(30, (8 - i) * 50 + 45, std::to_string(i), 1);
    }
    for (char j = 'a'; j < 'i'; ++j) {
        std::string str = "a";
        str[0] = j;
        window.drawBigString(50 + 50 * (j - 'a') + 20, 450, str, 1);
    }
    for (int a = 0; a < 8; ++a) {
        for (int b = 0; b < 8; ++b) {
            if ((a + b) % 2 == 0) {
                window.fillRectangle((50 * a) + 50, 50 * b + 10, 50, 50,
                                     window.Brown);
            } else {
                window.fillRectangle((50 * a) + 50, 50 * b + 10, 50, 50,
                                     window.White);
            }
        }
    }
}

void GraphicDisplay::notify() {
    int square_size = 50;
    for (int j = 0; j < 8; ++j) {
        for (int x = 0; x < 8; ++x) {
            if (Tochar(sub_gr->getPiece(j, x)) == " " && (x - j) % 2 != 0) {
                window.fillRectangle(j * square_size + square_size,
                                     x * square_size + 10, square_size,
                                     square_size, window.White);
            } else if (Tochar(sub_gr->getPiece(j, x)) == " " &&
                       (x - j) % 2 == 0) {
                window.fillRectangle(j * square_size + square_size,
                                     x * square_size + 10, square_size,
                                     square_size, window.Brown);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "K") {  // white
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "K", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "Q") {  // white
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "Q", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "B") {  // white
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "B", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "N") {  // white
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "N", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "R") {  // white
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "R", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "P") {  // white
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "P", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "k") {  // black
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "k", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "q") {  // black
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "q", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "b") {  // black
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "b", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "n") {  // black
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "n", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "r") {  // black
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "r", 1);
            } else if (Tochar(sub_gr->getPiece(j, x)) == "p") {  // black
                window.drawBigString(70 + (j * 50), (x)*50 + 45, "p", 1);
            }
        }
    }
}

string GraphicDisplay::Tochar(Piece *p) {
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

GraphicDisplay::~GraphicDisplay() { sub_gr->detach(this); }
