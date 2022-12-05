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

   protected:
    bool init_moved = false;  // check the pawn first move

   public:
    enum { King = 0, Queen = 1, Bishop = 2, Knight = 3, Rook = 4, Pawn = 5 };
    enum { white = 0, black = 1 };

   protected:
    Piece(int id, int colour);

   public:
    Piece(const Piece &pieces);
    int getColor();
    void init_move();
    virtual bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check valid movement

    virtual ~Piece() = default;

   public:
    const int &pid = id;
    const int &pcolour = colour;
};

#endif
