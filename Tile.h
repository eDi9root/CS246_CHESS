#ifndef _TILE_H
#define _TILE_H

#include "Board.h"
#include "Piece.h"

class Piece;

class Tile {
  int row;
  int col;

 public:
  Tile(int row, int col);
  bool get_empty_tile();
  void empty_tile();
  int getRow();
  int getCol();
  Piece* Piece();
};

std::ostream& operator<<(std::ostream& out, Tile& t);

#endif