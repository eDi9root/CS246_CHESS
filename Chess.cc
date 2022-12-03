#include "Chess.h"

#include "TextDisplay.h"

Chess::Chess() {
    board.init();
    // board.Render();
}

void Chess::turnmove() {
    string command[2];
    int x[2] = {
        0,
    };
    int y[2] = {
        0,
    };
    Piece *targetpiece = 0;
    cin >> command[0] >> command[1];  // 명령어 받기

    x[0] = command[0][0] - 'a';
    y[0] = 7 - (command[0][1] - '1');  // 이전 위치

    cout << x[0] << y[0] << endl;

    x[1] = command[1][0] - 'a';
    y[1] = 7 - (command[1][1] - '1');  // 목표 위치

    cout << x[1] << y[1] << endl;

    targetpiece = board.getPiece(x[0], y[0]);

    if (targetpiece->pcolour == colour) {
        if (board.getPiece(x[1], y[1]) && targetpiece->pcolour == colour) {
            if (targetpiece->check_attack(x[1], y[1], x[0], y[0])) {
                board.movement(x[1], y[1], x[0], y[0]);
                colour = !colour;
            }
        }
    } else {
        cout << "need to pass" << endl;
        if (targetpiece->check_move(x[1], y[1], x[0], y[0])) {
            board.movement(x[1], y[1], x[0], y[0]);
            colour = !colour;
        }
    }
}

void Chess::setup() {}

void Chess::run() {
    while (true) {
        graphics();
        cout << "1" << endl;
        board.Render();
        cout << "2" << endl;
        turnmove();
        cout << "3" << endl;
    }
}

void Chess::graphics() {
    unique_ptr<Observer> o;
    o = std::make_unique<TextDisplay>(&board);
    ob.push_back(std::move(o));
}
