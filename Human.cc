#include "Human.h"

#include "Piece.h"

Human::Human() {}

void Human::human_player(int turn) {
    string command[2];
    int x[2] = {
        0,
    };
    int y[2] = {
        0,
    };

    cin >> command[0] >> command[1];  // Command input

    x[0] = command[0][0] - 'a';
    y[0] = 7 - (command[0][1] - '1');  // original coordinate

    x[1] = command[1][0] - 'a';
    y[1] = 7 - (command[1][1] - '1');  // target coordinate

    turnmove();
}