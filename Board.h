#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <string>
#include <vector>

#include "Move.h"
#include "Piece.h"
#include "Tile.h"

using namespace std;

class Move;

class Board {
  Tile **theBoard;                 // 한 칸을 참조?
  vector<vector<Piece *>> pieces;  // 보드 [8][8]
  string piecesType;
  string colour;
  string positions;

 public:
  Board();
  bool Move(Move move);  // move class 를 가져와서 이동
  void setup_placeP(string piecesType, string positions);
  // bool legal_movement(string pieceType, string x, string y);

  ~Board();
};

#endif
