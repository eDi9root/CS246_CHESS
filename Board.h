#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"
using namespace std;

class Board : public Piece
{
    // Tile **theBoard;
    vector<vector<Piece *>> pieces; // 이중 vector 이어야 할듯?
    string piecesType;
    string colour;
    string positions;

public:
    Board();
    void setup_placeP(string piecesType, string positions);
    // bool legal_movement(string pieceType, string x, string y);

    ~Board();
};

#endif
