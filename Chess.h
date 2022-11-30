#ifndef _CHESS_H
#define _CHESS_H
#include "Board.h"
#include "Piece.h"
#include "Player.h"

class Chess {
    Board **board;
    Player *players;
    bool playing;

   public:
    Chess(*players);
    void resign();
    void reset();
    void turnmove();
    void setup();
    void run();
};

#endif
