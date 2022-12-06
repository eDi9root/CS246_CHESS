#include "Piece.h"

#include <iostream>
using namespace std;

Piece::Piece(int id, int colour) : id(id), colour(colour) {}

Piece::Piece(const Piece &pieces) : id(pieces.pid), colour(pieces.pcolour) {}

int Piece::getColor() { return colour; }

void Piece::init_move() { init_moved = true; }

void Piece::init_move_king() { init_moved_king = true; }

void Piece::init_move_Rook() { init_moved_Rook = true; }

void Piece::enpassant() { en_passant = true; }

bool Piece::check_move(int ax, int ay, int bx, int by, Board &board) const {
    return (!(ax < 0 || ax >= 8 || ay < 0 || ay >= 8)) &&
           (!(ax == bx && ay == by));
}
