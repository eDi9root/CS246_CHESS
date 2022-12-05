#ifndef _CHESS_H
#define _CHESS_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Board.h"
#include "Player.h"
#include "observer.h"

using namespace std;

class Chess {
    Board board;
    vector<unique_ptr<Observer>> ob;
    bool playing;
    bool end_game = true;

    unsigned int colour = Piece::white;

   protected:
    float winner_white = 0;
    float winner_black = 0;

   public:
    Chess();
    void count_winner(int colour);
    void count_draw(int colour);
    int printW();
    int printB();
    void turnmove();
    void setup();
    void run();
    void graphics();
};

#endif
