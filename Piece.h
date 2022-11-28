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
  virtual int calculate_coord_x(char letter);
  virtual int calculate_coord_y(char number);
  virtual bool getcheck(char origin_x, char origin_y, char new_x, char new_y) const;

  virtual bool movement() = 0;
};

#endif
