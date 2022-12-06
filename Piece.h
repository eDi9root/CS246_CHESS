#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <string>

using namespace std;
class Board;

class Piece {
   private:
    int id;      // Type
    int colour;  // Team

   protected:
    bool init_moved = false;       // check the pawn first move
    bool init_moved_king = false;  // check the king first move for caslte
    bool init_moved_Rook = false;  // check the Rook first move for castle
    bool en_passant = false;       // check the valid en passant

   public:
    // using enum to make it clear
    enum { King = 0, Queen = 1, Bishop = 2, Knight = 3, Rook = 4, Pawn = 5 };
    enum { white = 0, black = 1 };

   protected:
    Piece(int id, int colour);

   public:
    Piece(const Piece &pieces);
    int getColor();         // get colour;
    void init_move();       // if the pawn moved, then make it true
    void init_move_king();  // if the King moved, then make it true
    void init_move_Rook();  // if the Rook moved, then make it true

    void enpassant();  // if en passant movement possible, then make it true;

    virtual bool check_move(int ax, int ay, int bx, int by, Board &board) const;
    // check valid movement

    virtual ~Piece() = default;

   public:
    const int &pid = id;
    const int &pcolour = colour;
};

#endif
