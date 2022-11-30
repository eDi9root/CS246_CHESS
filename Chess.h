#ifndef _CHESS_H
#define _CHESS_H
#include "Board.h"
#include "Piece.h"
#include "Player.h"

class Chess {
    Board board;
    Player *player1;
    Player *player2;
    bool playing;

   public:
    Chess(Player *player1, Player *player2);
    void resign();
    void reset();
    void turnmove();
    void setup();
    void game();
};

#endif
