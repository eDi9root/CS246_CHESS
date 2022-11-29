#include "Board.h"

#include <iostream>
#include <vector>

#include "Chess.h"
#include "Piece.h"
#include "PiecesType.h"
#include "Player.h"
#include "TextDisplay.h"

using namespace std;

Board::Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      pBoard[i][j] = 0;
    }
  }
}

/*
void Board::init() {
  string colour = "black";
  int y1 = 0;
  int y2 = 1;
  for (int j = 0; j < 2; ++j) {
    pBoard[0][y1] = new Rook(colour);  // black
    pBoard[1][y1] = new Knight(colour);
    pBoard[2][y1] = new Bishop(colour);
    pBoard[3][y1] = new Queen(colour);
    pBoard[4][y1] = new King(colour);
    pBoard[5][y1] = new Bishop(colour);
    pBoard[6][y1] = new Knight(colour);
    pBoard[7][y1] = new Rook(colour);
    for (int i = 0; i < 8; ++i) {
      pBoard[i][y2] = new Pawn(colour);
    }
    y1 = 7;
    y2 = 6;
    colour = "white";
  }
}
*/

void Board::setup_placeP(char piecesType, char x, char y) {
    int change_x_int = x - 97;
    int change_y_int = 7 - (y - 49);
    if (piecesType == 'k') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new King("black");
    } else if (pieceType == 'q') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Queen("black");
    } else if (pieceType == 'b') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Bishop("black");
    } else if (pieceType == 'r') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Rook("black");
    } else if (pieceType == 'n') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Knight("black");
    } else if (piecesType == 'p') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Pawn("black");      
    } else if (piecesType == 'K') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new King("white");
    } else if (pieceType == 'Q') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Queen("white");
    } else if (pieceType == 'B') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Bishop("white");
    } else if (pieceType == 'W') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Rook("white");
    } else if (pieceType == 'N') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Knight("white");
    } else if (piecesType == 'P') {
      board[x][y].setRow = x;
      board[x][y].setCol = y;
      board[x][y].setPiece = new Pawn("white"); 
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

     return true;
}

// void Board::setup_placeP
