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
    Piece *attackpiece = 0;

    cin >> command[0] >> command[1];  // 명령어 받기

    x[0] = command[0][0] - 'a';
    y[0] = 7 - (command[0][1] - '1');  // 이전 위치

    x[1] = command[1][0] - 'a';
    y[1] = 7 - (command[1][1] - '1');  // 목표 위치

    targetpiece = board.getPiece(x[0], y[0]);
    attackpiece = board.getPiece(x[1], y[1]);

    if (targetpiece->pcolour == colour) {
        if (attackpiece && (attackpiece->pcolour != colour)) {
<<<<<<< HEAD
=======
            if (targetpiece->check_attack(x[1], y[1], x[0], y[0], board)) {
                if (board.movement(x[1], y[1], x[0], y[0])) {
                    colour = !colour;
                    cout << colour << endl;
                    if (board.getPiece(x[1],y[1])->pid == Piece::King) {
                        if (board.getPiece(x[1],y[1])->getColor() == Piece::black) {
                            board.set_new_blackking_x(x[1]);
                            board.set_new_blackking_y(y[1]);
                        } else {
                            board.set_new_whiteking_x(x[1]);
                            board.set_new_whiteking_y(y[1]);
                        }
                    }
                }
            }
        } else {
>>>>>>> bd3ab4827784f7e689d6af44235c6d7d2dd3cf6b
            if (targetpiece->check_move(x[1], y[1], x[0], y[0], board)) {
                if (board.movement(x[1], y[1], x[0], y[0])) {
                    colour = !colour;
                    cout << colour << endl;
                    if (board.getPiece(x[1],y[1])->pid == Piece::King) {
                        if (board.getPiece(x[1],y[1])->getColor() == Piece::black) {
                            board.set_new_blackking_x(x[1]);
                            board.set_new_blackking_y(y[1]);
                        } else {
                            board.set_new_whiteking_x(x[1]);
                            board.set_new_whiteking_y(y[1]);
                        }
                    }
                }
            }
        }
    } else {
        if (targetpiece->check_move(x[1], y[1], x[0], y[0], board)) {
            if (board.movement(x[1], y[1], x[0], y[0])) {
                colour = !colour;
                cout << colour << endl;
            }
        }
    }
    board.check();
}

void Chess::setup() {}

void Chess::run() {
    graphics();
    while (true) {
        board.Render();
        turnmove();
    }
}

void Chess::graphics() {
    unique_ptr<Observer> o;
    o = std::make_unique<TextDisplay>(&board);
    ob.push_back(std::move(o));
}
