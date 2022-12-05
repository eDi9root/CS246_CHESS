#include "Computers.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void Computers::level_one(int colour, Board& B) {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    bool cont = true;
    srand((unsigned int)time(NULL));
    while (cont) {
        int command = rand();
        x1 = (int)command % 8;
        y1 = (int)command % 8;
        x2 = (int)command % 8;
        y2 = (int)command % 8;

        Piece* targetpiece = 0;

        targetpiece = B.getPiece(x1, y1);

        if (targetpiece == 0) {
        } else if (!(targetpiece->check_move(x2, y2, x1, y1, B))) {
        } else if (targetpiece->pcolour != colour) {
        } else {
            B.movement(x2, y2, x1, y1);
            cont = false;
        }
    }
}
