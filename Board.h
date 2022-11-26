#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <vector>
#include "Piece.h"
using namespace std;

class Board: public Piece{
    vector <Piece *> pieces;
    string pieces;
    string colour;
    string positions;
    public:
    Board();
    
    ~Board();
};

#endif
