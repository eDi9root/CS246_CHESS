#include "PiecesType.h"

#include <iostream>

#define abs(x) ((x) < 0 ? -(x) : (x))

King::King(std::string colour) : Piece(Piece::King, colour) {}

bool King::check_move(int ax, int ay, int bx, int by) const {
  // 한칸씩 이동 가능
  if (ax >= bx - 1 && ax <= bx + 1) {
    if (ay >= by - 1 && ay <= by + 1) {
      return Piece::check_move(ax, ay, bx, by);
    }
  }
  return false;
}

Queen::Queen(std::string colour) : Piece(Piece::Queen, colour) {}

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

Bishop::Bishop(std::string colour) : Piece(Piece::Bishop, colour) {}

bool Bishop::check_move(int ax, int ay, int bx, int by) const {
  // bishop은 대각선만
  if (abs(ax - bx) == abs(ay - by)) {
    return Piece::check_move(ax, ay, bx, by);
  }
  return false;
}

Rook::Rook(std::string colour) : Piece(Piece::Rook, colour) {}

bool Rook::check_move(int ax, int ay, int bx, int by) const {
  // 룩은 직선만
  if (ax == bx) {
    return Piece::check_move(ax, ay, bx, by);
  } else if (ay == by) {
    return Piece::check_move(ax, ay, bx, by);
  }
  return false;
}

Knight::Knight(std::string colour) : Piece(Piece::Knight, colour) {}

bool Knight::check_move(int ax, int ay, int bx, int by) const {
  if (abs(1 - bx) == ax) {
    if (abs(2 - by) == ay) {
      return Piece::check_move(ax, ay, bx, by);
    }
  } else if (abs(2 - bx) == ax) {
    if (abs(1 - by) == ay) {
      return Piece::check_move(ax, ay, bx, by);
    }
  }
  return false;
}

Pawn::Pawn(std::string colour) : Piece(Piece::Pawn, colour) {}

bool Pawn::check_move(int ax, int ay, int bx, int by) const {
  if (pcolour == "black") {
    if (ax = bx && (ay > by && ay - 2 <= by)) {
      return Piece::check_move(ax, ay, bx, by);
    }
  } else {
    if (ax == bx && (ay < by && ay + 2 >= by)) {
      return Piece::check_move(ax, ay, bx, by);
    }
  }
  return false;
}

bool Pawn::check_attack(int ax, int ay, int bx, int by) const {
  if (pcolour == "black") {
    if ((abs(1 + ax) == bx) && (ay - 1 == by)) {
      return true;
    }
  } else {
    if ((abs(1 - ax) == bx) && (ay + 1 == by)) {
      return true;
    }
  }
  return false;
}