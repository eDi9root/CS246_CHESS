#include "Computers.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Computers::Computers(int level, int colour, Board& B) {
    if (level == 1) {
        level_one(colour, B);
    } else if (level == 2) {
        level_two(colour, B);
    }
}

void Computers::level_one(int colour, Board& B) {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    bool cont = true;
    srand((unsigned int)time(NULL));
    while (cont) {
        int arr[4];
        for (int i = 0; i < 4; i++) {
            arr[i] = rand() % 8;
        }

        Piece* targetpiece = 0;

        targetpiece = B.getPiece(arr[0], arr[1]);

        if (targetpiece == 0) {
            continue;
        } else if (!(targetpiece->check_move(arr[2], arr[3], arr[0], arr[1],
                                             B))) {
            continue;
        } else if (targetpiece->pcolour != colour) {
            continue;
        } else {
            B.movement(arr[2], arr[3], arr[0], arr[1]);
            colour = !colour;
            cont = false;
        }
    }
}

void Computers::level_two(int colour, Board& B) {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    bool cont = true;
    int count = 0;

    srand((unsigned int)time(NULL));
    while (cont) {
        int arr[4];
        for (int i = 0; i < 4; i++) {
            arr[i] = rand() % 8;
        }

        Piece* targetpiece = 0;
        Piece* attackpiece = 0;

        targetpiece = B.getPiece(arr[0], arr[1]);
        attackpiece = B.getPiece(arr[2], arr[3]);

        if (targetpiece == 0) {
            count++;
            continue;
        } else if (!(targetpiece->check_move(arr[2], arr[3], arr[0], arr[1],
                                             B))) {
            count++;
            continue;
        } else if (targetpiece->pcolour != colour) {
            count++;
            continue;
        } else if (attackpiece != 0) {
            B.movement(arr[2], arr[3], arr[0], arr[1]);
            colour = !colour;
            cont = false;
        } else if (count > 1000) {
            B.movement(arr[2], arr[3], arr[0], arr[1]);
            colour = !colour;
            cont = false;
        }
        count++;
    }
}
