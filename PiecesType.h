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

  // bool getcheck();
  bool movement();

  friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

class Queen : public Piece {
 public:
  Queen(std::string colour);
  bool getcheck(char origin_x, char origin_y, char new_x, char new_y) const;
  // bool movement();
};

class Bishop : public Piece {
 public:
  bool getcheck(char origin_x, char origin_y, char new_x, char new_y) const;
};

class Rook : public Piece {
 public:
  bool getcheck(char origin_x, char origin_y, char new_x, char new_y) const;
};

class Knight : public Piece {
 public:
  bool getcheck(char origin_x, char origin_y, char new_x, char new_y) const;
};

class Pawn : public Piece {
 private:
  bool castle = true;

 public:
  Pawn(std::string colour);

  bool getcheck();
  bool movement();

  friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

#endif
