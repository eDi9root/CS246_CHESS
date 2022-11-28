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
  bool movement() const;

  friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

class Queen : public Piece {
 public:
  Queen(std::string colour);

  // bool getcheck();
  bool Movement() const;
};

class Bishop : public Piece {
 public:
  Bishop(std::string colour);

  // bool getcheck();
  bool Movement() const;
};

class Rook : public Piece {
 public:
  Rook(std::string colour);

  // bool getcheck();
  bool Movement() const;
};

class Knight : public Piece {
 public:
  Knight(std::string colour);

  // bool getcheck();
  bool Movement() const;
};

class Pawn : public Piece {
 private:
  bool enpassen = true;
  bool init_two_move = true;

 public:
  Pawn(std::string colour);

  bool getcheck() const;
  bool movement() const;

  friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

#endif
