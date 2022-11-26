#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"
using namespace std;

class Board: public Piece{
    //Tile **theBoard;
    vector <Piece *> pieces;
    string piecesType;
    string colour;
    string positions;
public:
    Board();

    ~Board();
};

#endif
