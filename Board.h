#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <string>
#include <vector>

#include "Move.h"
#include "Piece.h"
#include "Tile.h"
using namespace std;

class Pieces;

class Move;

class Board {
  // Tile **theBoard;
  vector<vector<Piece*>> pieces;  // 이중 vector 이어야 할듯?
  // Tile** theBoard;
  string piecesType;
  string colour;
  string positions;

 public:
  Board();
  bool Move(Move move);
  void setup_placeP(string piecesType, string positions);
  // bool legal_movement(string pieceType, string x, string y);

  ~Board();
};

#endif
