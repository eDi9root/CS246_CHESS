#ifndef _CHESS_H
#define _CHESS_H
#include "Board.h"
#include "Player.h"

class Chess {
  Board board;
  Player player;

 public:
  void resign();
  void reset();
  void turnmove();
  void setup();
};

#endif
