#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Board;

class Piece {
  protected:
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
  virtual string printpiece() = 0;
  virtual ~Piece() = default;

  // Move movement(Board board) const;  // 이동

 public:
  const int &pid = id;
  const string &pcolour = colour;
};

#endif
