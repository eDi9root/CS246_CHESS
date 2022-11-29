#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <string>

#include "Board.h"
#include "Tile.h"
using namespace std;

class Board;

class Piece {
  int id;         // Itype
  string colour;  // iTeam
  string position;
  bool captured;
  bool init_moved;

 public:
  Piece();
  virtual bool check_move(int ax, int ay, int bx, int by) const;
  // 이동 가능 확인

  virtual bool check_attack(int ax, int ay, int bx, int by) const;
  // 공격 가능 확인

  // Move movement(Board board) const;  // 이동
};

#endif
