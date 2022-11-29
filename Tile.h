#ifndef _TILE_H
#define _TILE_H

#include <string>

#include "Piece.h"

using namespace std;

class Piece;

class Tile {
  int row;
  int col;
  string position;
  Piece *piecethatisonTile;

 public:
  Tile();
  bool get_empty_tile();
  int getRow();
  int getCol();
  Piece *getPiece();
  // string getPos();

  void setRow(char x);
  void setCol(char y);
  // void setPos(string pos);
  void setPiece(Piece *piece);

  ~Tile();
};

// std::ostream& operator<<(std::ostream& out, Tile& t);

#endif