#ifndef _PIECESTYPE_H
#define _PIECESTYPE_H

#include <iostream>
#include <string>
#include <vector>

#include "Board.h"
#include "Piece.h"
#include "Tile.h"

class King : public Piece {
   private:
    bool castle = true;

   public:
    King(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;

    friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

class Queen : public Piece {
   public:
    Queen(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
};

class Bishop : public Piece {
   public:
    Bishop(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
};

class Rook : public Piece {
   public:
    Rook(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
};

class Knight : public Piece {
   public:
    Knight(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
};

class Pawn : public Piece {
   private:
    bool enpassen = true;
    bool init_two_move = false;

   public:
    Pawn(int colour);

    bool check_ally(int ax, int ay, int bx, int by, Board &board) const;
    bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    bool check_init_move(bool init_two_move) const;

    friend class Board;  // castle 변수의 접근을 위해 Board 를 friend 로 선언?
};

#endif
