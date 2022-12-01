#include "Chess.h"

#include "TextDisplay.h"

Chess::Chess() {
    board.init();
    board.Render();
}

void Chess::turnmove() {}

void Chess::setup() {}

void Chess::run() { board.Render(); }

void Chess::graphics() {
    unique_ptr<Observer> o;
    o = std::make_unique<TextDisplay>(&board);
    ob.push_back(std::move(o));
}
