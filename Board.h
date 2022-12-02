#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Subject.h"

using namespace std;

class Board : public Subject {
    // vector<vector<Tile>> pBoard;  // 한 칸을 참조?
    // vector<Tile> pBoard2;
    Piece* pBoard[8][8];
    string piecesType;
    string colour;
    string positions;

   public:
    Board();
    void init();
    void Render();
    // unique_ptr<Piece> *getPiece(int x, int y);
    Piece* getPiece(int x, int y);
    const Piece* getPiece(int x, int y) const;
    bool movement(int ax, int ay, int bx,
                  int by);  // move class 를 가져와서 이동
    // void setup_placeP(char piecesType, char c, char y);
    // bool legal_movement(string pieceType, string x, string y);

    ~Board();
};

#endif
