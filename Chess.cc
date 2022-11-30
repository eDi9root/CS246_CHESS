#include "Chess.h"

#include "TextDisplay.h"

Chess::Chess() {}  // board.init();

void Chess::run() {}

void Chess::graphics() {
    unique_ptr<Observer> o;
    o = std::make_unique<TextDisplay>(&board);
    ob.push_back(std::move(o));
}
