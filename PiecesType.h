#ifndef _PIECESTYPE_H
#define _PIECESTYPE_H

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"

class King : public Piece {
 private:
  bool castle = true;

 public:
  King(std::string colour);

  bool check_move(int ax, int ay, int bx, int by) const;

  friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

class Queen : public Piece {
 public:
  Queen(std::string colour);
  bool check_move(int ax, int ay, int bx, int by) const;
};

class Bishop : public Piece {
 public:
  Bishop(std::string colour);
  bool check_move(int ax, int ay, int bx, int by) const;
};

class Rook : public Piece {
 public:
  Rook(std::string colour);
  bool check_move(int ax, int ay, int bx, int by) const;
};

class Knight : public Piece {
 public:
  Knight(std::string colour);
  bool check_move(int ax, int ay, int bx, int by) const;
};

class Pawn : public Piece {
 private:
  bool enpassen = true;
  bool init_two_move = true;

 public:
  Pawn(std::string colour);

  bool check_move(int ax, int ay, int bx, int by) const;
  bool check_attack(int ax, int ay, int bx, int by) const;

  friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

#endif
