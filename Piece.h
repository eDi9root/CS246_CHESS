#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
using namespace std;

class Board;

class Piece {
    int id;
    int row, col;
    string colour;
    
public:
    bool getcheck(string position);

};

#endif
