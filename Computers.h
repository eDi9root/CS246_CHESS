#ifndef _COMPUTERS_H
#define _COMPUTERS_H

#include "Board.h"
#include "Player.h"

class Computers : public Player {
    int level;

   public:
    Computers(int level);
    void level_one(int turn, Board &B);
    void level_two(int turn, Board &B);
    void level_three(int turn, Board &B);
    void level_four(int turn, Board &B);
    virtual ~Computers() = default;
};

#endif
