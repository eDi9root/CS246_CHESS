#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "Player.h"

using namespace std;

class Human : public Player {
    Human(int turn);
};

#endif
