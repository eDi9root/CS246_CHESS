#ifndef _TILE_H
#define _TILE_H

#include "Piece.h"

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
  Piece* getPiece();
  string getPos();

/*
  void setRow(int x);
  void setCol(int y);
  */
  void setPos(string pos);
  void setPiece(Piece *piece);

  ~Tile();
};

//std::ostream& operator<<(std::ostream& out, Tile& t);

#endif