#include "GraphicDisplay.h"

#include <iostream>
#include <string>

#include "Board.h"
#include "Piece.h"
#include "window.h"

GraphicDisplay::GraphicDisplay(Board *sub) : sub_gr{sub} {
    sub_gr->attach(this);
}
