#ifndef _MOVE_H
#define _MOVE_H

#include "Piece.h"

class Move {
 public:
  int init_row();
  int init_col();
  int end_row();
  int end_col();
  Piece* capt_peice();
  bool set_promo;
};

#endif
