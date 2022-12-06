#ifndef _COMPUTERS_H
#define _COMPUTERS_H

#include "Board.h"
#include "Chess.h"
#include "Piece.h"

class Computers {
    int level;
    int colour;

   public:
    Computers(int level, int colour, Board &B);
    void level_one(int colour, Board &B);
    void level_two(int colour, Board &B);
    void level_three(int colour, Board &B);
    void level_four(int colour, Board &B);
    virtual ~Computers() = default;
};

#endif
