#ifndef _PIECESTYPE_H
#define _PIECESTYPE_H

#include <iostream>
#include <string>
#include <vector>

#include "Board.h"
#include "Piece.h"

class King : public Piece {
   private:
    bool castle = false;

   public:
    King(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    // check if there is an ally at the destination
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check the entire movement
    bool check_castle(int ax, int ay, int bx, int by, Board &board) const;
    // check castling movement

    friend class Board;  // To approach castle
};

class Queen : public Piece {
   public:
    Queen(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    // check if there is an ally at the destination
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check the entire movement
};

class Bishop : public Piece {
   public:
    Bishop(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    // check if there is an ally at the destination
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check the entire movement
};

class Rook : public Piece {
   public:
    Rook(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    // check if there is an ally at the destination
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check the entire movement
};

class Knight : public Piece {
   public:
    Knight(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    // check if there is an ally at the destination
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check the entire movement
};

class Pawn : public Piece {
   private:
    bool enpassen = true;

   public:
    Pawn(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    // check if there is an ally at the destination
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check the entire movement

    friend class Board;
};

#endif
