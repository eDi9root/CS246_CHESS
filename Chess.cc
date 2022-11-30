#include "Chess.h"

#include "TextDisplay.h"

Chess::Chess(Player *players) {
    players[0] = "white";
    players[1] = "black";
}

void Chess::run() {
    board.init();
    // board.render();
}
