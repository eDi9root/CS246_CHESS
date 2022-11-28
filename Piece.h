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

  virtual bool movement() const;
};

#endif
