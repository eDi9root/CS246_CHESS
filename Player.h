#ifndef _PLAYER_H
#define _PLAYER_H

#include "Chess.h"

class Player : public Chess {
  std::string turn;

 public:
  Move player();
};

#endif
