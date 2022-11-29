#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <string>

#include "Board.h"
#include "PiecesType.h"
#include "Tile.h"
using namespace std;

class Board;

class Piece {
  int id;         // Itype
  string colour;  // iTeam
                  // string position;
                  // bool captured;
                  // bool init_moved;

 public:
  enum { King = 0, Queen = 1, Bishop = 2, Knight = 3, Rook = 4, Pawn = 5 };

 public:
  Piece(const Piece &pieces);
  Piece(int id, string colour);
  virtual bool check_move(int ax, int ay, int bx, int by) const;
  // 이동 가능 확인

  virtual bool check_attack(int ax, int ay, int bx, int by) const;
  // 공격 가능 확인

  // Move movement(Board board) const;  // 이동

 public:
  const int &pid = id;
  const string &pcolour = colour;
};

#endif
