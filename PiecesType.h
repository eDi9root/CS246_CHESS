#ifndef _PIECESTYPE_H
#define _PIECESTYPE_H

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"

using namespace std;

class King : public Piece
{

public:
    bool getcheck();
};

#endif
