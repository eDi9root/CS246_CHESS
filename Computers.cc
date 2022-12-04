#include "Computers.h"

#include <iostream>
#include <string>

using namespace std;

Computers::Computers(int turn) : Player{turn} {}

void Computers::level_one(int turn, Board &B) {
    B.movement(rand() % 8, rand() % 8, rand() % 8, rand() % 8);
}