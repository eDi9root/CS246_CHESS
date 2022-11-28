#include "Board.h"

#include <iostream>
#include <vector>

#include "Chess.h"
#include "Piece.h"
#include "PiecesType.h"
#include "Player.h"
#include "TextDisplay.h"
//#inlcude ""
using namespace std;

void Board::init() { vector<vector<Piece>> pBoard(8, vector<Piece>(8, NULL)); }

bool Board::movement(int ax, int ay, int bx, int by) {
  // 이거 vector 로 다시 써야함
  //   // 이동할 곳에 말이 있으면 제거
  //   if (pBoard[ax][ay]) {
  //     delete pBoard[ax][ay];
  //   }
  //   // 단순히 이동
  //   pBoard[ax][ay] = pBoard[bx][by];

  //   // 이동 완료될 경우 지나간 자리는 0 또는 null 로
  //   pBoard[bx][by] = 0;

  //   return true;
}

// void Board::setup_placeP
