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
  virtual bool getcheck(string position) const;

  //   enum { Black = 0, white = 1 };

  virtual bool getcheck(string position) = 0;

  virtual bool movement() = 0;
};

#endif
