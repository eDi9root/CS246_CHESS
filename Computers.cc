#include "Computers.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void Computers::level_one(int colour, Board &B) {
    srand((unsigned int)time(NULL));
    while (true) {
        int command = rand();
        B.movement((int)command % 8, (int)command % 8, (int)command % 8,
                   (int)command % 8);
    }
}
