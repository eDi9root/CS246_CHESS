#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "Chess.h"
#include "Piece.h"

using namespace std;

class Human {
   public:
    Human();
    void human_player(int turn);
};

#endif
