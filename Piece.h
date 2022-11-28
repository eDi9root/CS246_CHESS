#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
using namespace std;

class Board;

class Piece {
  int id;
  int row, col;
  string colour;

 public:
  //   enum { King = 0, Queen = 1, Bishop = 2, Knight = 3, Rock = 4, Pawn = 5 };

  //   enum { Black = 0, white = 1 };
  virtual bool getcheck(string origin_x, string origin_y, string new_x, string new_y) = 0;

  virtual bool movement() = 0;
};

#endif
