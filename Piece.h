#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>

#include "Board.h"
#include "Tile.h"
using namespace std;

class Board;

class Piece {
  int id;
  string colour;
  Tile* position;
  bool captured;
  bool init_moved;

 public:
  Piece();
  virtual bool getcheck(int ax, int ay, int bx,
                        int by) const;  // 이동 가능 확인

  // Move movement(Board board) const;  // 이동
};

#endif
