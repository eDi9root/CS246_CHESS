#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Subject.h"

using namespace std;

class Board : public Subject {
    Piece* pBoard[8][8];
    string piecesType;
    string colour;
    string positions;
    int blackKing_x;
    int blackKing_y;
    int whiteKing_x;
    int whiteKing_y;

   public:
    Board();
    void init();

    void set_new_blackking_x(int x);
    void set_new_blackking_y(int y);
    void set_new_whiteking_x(int x);
    void set_new_whiteking_y(int y);

    void Render();
    Piece* getPiece(int x, int y);
    const Piece* getPiece(int x, int y) const;
    bool movement(int ax, int ay, int bx,
                  int by);  // actual movement
    bool checkmate(int colour);
    bool check(int colour, Board& board);

    ~Board();
};

#endif
