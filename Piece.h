#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Board;

class Piece {
   private:
    int id;      // Itype
    int colour;  // iTeam
                 // string position;
                 // bool captured;
                 // bool init_moved;

   public:
    enum { King = 0, Queen = 1, Bishop = 2, Knight = 3, Rook = 4, Pawn = 5 };
    enum { white = 0, black = 1 };

   protected:
    Piece(int id, int colour);

   public:
    Piece(const Piece &pieces);
    int getColor();
    virtual bool check_move(int ax, int ay, int bx, int by) const;
    // 이동 가능 확인

    virtual bool check_attack(int ax, int ay, int bx, int by) const;
    // 공격 가능 확인
    virtual ~Piece() = default;

    // Move movement(Board board) const;  // 이동

   public:
    const int &pid = id;
    const int &pcolour = colour;
};

#endif
