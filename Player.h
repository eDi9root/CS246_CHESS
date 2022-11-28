#ifndef _PLAYER_H
#define _PLAYER_H

#include "Chess.h"

class Player : public Chess {
  Player player1;
  Player player2;
  std::string turn;

 public:
  Move player();
};

#endif