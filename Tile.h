#ifndef _TILE_H
#define _TILE_H

#include "Board.h"

class Tile {
 public:
  int getRow();
  int getCol();
  Piece* Piece();
};

#endif