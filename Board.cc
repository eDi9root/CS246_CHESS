#include "Board.h"

#include <iostream>
#include <vector>

#include "Chess.h"
#include "Piece.h"
#include "PiecesType.h"
#include "Player.h"
#include "TextDisplay.h"

using namespace std;

Board::Board() { vector<vector<Tile>> pBoard(8, vector<Tile>(8, 0)); }

void Board::init() {
  vector<vector<Piece>> pBoard(8, vector<Piece>(8, 0));
  // string;
  int y1 = 0;
  int y2 = 1;
  for (j = 0; j < 2; ++j) {
    pBoard[0][y1] = new Rook();  // black
    pBoard[1][y1] = new Knight();
    pBoard[2][y1] = new Bishop();
    pBoard[3][y1] = new Queen();
    pBoard[4][y1] = new King();
    pBoard[5][y1] = new Bishop();
    pBoard[6][y1] = new Knight();
    pBoard[7][y1] = new Rook();
    for (int i = 0; i < 8; ++i) {
      pBoard[i][y2] = new Pawn();
    }
    y1 = 7;
    y2 = 6;
    // player 도 바꿔주기
  }
}

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
