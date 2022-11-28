#ifndef _CHESS_H
#define _CHESS_H
#include "Board.h"
#include "Player.h"

class Chess {
  Board board;
  Player players;

 public:
  void resign();
  void reset();
  void turnmove();
  void setup();
  void game();
};

#endif
