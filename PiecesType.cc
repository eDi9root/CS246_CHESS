#include "PiecesType.h"

#include <iostream>

#define abs(x) ((x) < 0 ? -(x) : (x))

King::King(std::string colour) : Piece(Piece::King, colour) {}

bool King::check_move(int ax, int ay, int bx, int by) const {
  // 한칸씩 이동 가능
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

bool Rook::check_move(int ax, int ay, int bx, int by) const {
  // 룩은 직선만
  if (ax == bx) {
    return Piece::check_move(ax, ay, bx, by);
  } else if (ay == by) {
    return Piece::check_move(ax, ay, bx, by);
  }
  return false;
}

bool Bishop::check_move(int ax, int ay, int bx, int by) const {
  // bishop은 대각선만
  if (abs(ax - bx) == abs(ay - by)) {
    return Piece::check_move(ax, ay, bx, by);
  }
  return false;
}
