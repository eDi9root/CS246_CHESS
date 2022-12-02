#include "Piece.h"

#include <iostream>
using namespace std;

Piece::Piece(int id, int colour) : id(id), colour(colour) {}

Piece::Piece(const Piece &pieces) : id(pieces.pid), colour(pieces.pcolour) {}

int Piece::getColor() { return colour; }

bool Piece::check_move(int ax, int ay, int bx, int by) const {
    return (!(ax < 0 || ax >= 8 || ay < 0 || ay >= 8)) &&
           (!(ax == bx && ay == by));
}

bool Piece::check_attack(int ax, int ay, int bx, int by) const {
    return Piece::check_move(ax, ay, bx, by);
}
