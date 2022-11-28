#ifndef _PIECESTYPE_H
#define _PIECESTYPE_H

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"

using namespace std;

class King : public Piece {
 private:
  bool castle = true;

 public:
  King(std::string colour);
  bool getcheck(string origin_x, string origin_y, string new_x, string new_y);
  bool movement();

  friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};


class Queen : public Piece {
 public:
  Queen(std::string colour);
  bool getcheck(string origin_x, string origin_y, string new_x, string new_y);
  //bool movement();
};

class Bishop : public Piece {
  public:
  bool getcheck(string origin_x, string origin_y, string new_x, string new_y);

};

class Rook : public Piece {
  public:
  bool getcheck(string origin_x, string origin_y, string new_x, string new_y);
};

class Knight : public Piece {
  public:
  bool getcheck(string origin_x, string origin_y, string new_x, string new_y);

};

class 

#endif
