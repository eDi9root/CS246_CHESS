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
    unique_ptr<Player> players[2];
    vector<unique_ptr<Observer>> ob;
    bool playing;

    unsigned int colour = Piece::white;

   public:
    Chess();
    // void resign();
    // void reset();
    void turnmove();
    void setup();
    void run();
    void graphics();
};

#endif
