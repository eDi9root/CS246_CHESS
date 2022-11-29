#include "PiecesType.h"

#include <iostream>

#define abs(x) ((x) < 0 ? -(x) : (x))

bool King::check_move(int ax, int ay, int bx, int by) const {
  // 킹은 한칸씩 이동 가능
}

bool Queen::check_move(int ax, int ay, int bx, int by) const {
  // 퀸은 모든 이동 가능 (나이트 제외)
  if (ax == bx) {
    return Piece::check_move(ax, ay, bx, by);
  } else if (ay == by) {
    return Piece::check_move(ax, ay, bx, by);
  } else {
    if (abs(ax - bx) == abs(ay - by)) {
      return Piece::check_move(ax, ay, bx, by);
    }
  }
  return false;
}
