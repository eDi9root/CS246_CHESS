#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <string>
#include <vector>

//#include "Move.h"
#include "Piece.h"
#include "Subject.h"
#include "Tile.h"

using namespace std;

class TextDisplay;

class Tile;

class Piece;

class Board : public Subject {
  Tile **pBoard;  // 한 칸을 참조?
  string piecesType;
  string colour;
  string positions;

 public:
  Board();
  void init();
  Piece *getPiece(int x, int y);
  Tile *getTile();
  bool movement(int ax, int ay, int bx, int by);  // move class 를 가져와서 이동
  void setup_placeP(char piecesType, char c, char y);
  // bool legal_movement(string pieceType, string x, string y);

  ~Board();
};

#endif
