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
  virtual bool getcheck(int origin_x, int origin_y, int new_x, int new_y) const;

  virtual bool movement() = 0;
};

#endif
