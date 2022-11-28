#include "Board.h"

#include <iostream>
#include <vector>

#include "Chess.h"
#include "PiecesType.h"
#include "TextDisplay.h"
#include "Piece.h"
#include "Player.h"
//#inlcude ""
using namespace std;

void Board::init() {
    vector <vector<Piece>> pBoard(8,vector<Piece>(8,NULL));
    pBoard[0][0] = new Rook(Player.Player1);
    //pBoard[0][1] = new Piece;
    //pBoard[0][2] = new Piece

}

//void Board::setup_placeP
