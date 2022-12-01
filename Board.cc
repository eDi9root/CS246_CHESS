#include "Board.h"

#include <iostream>
#include <vector>

#include "Chess.h"
#include "Piece.h"
#include "PiecesType.h"
#include "Player.h"
#include "TextDisplay.h"
#include "Tile.h"

using namespace std;

Board::Board() {
    Tile t;
    for (int i = 0; i < 8; i++) {
        vector<Tile> rows;
        pBoard.push_back(rows);
        for (int j = 0; j < 8; j++) {
            pBoard.at(i).push_back(t);
        }
    }
}

void Board::init() {
    string colour = "black";
    int y1 = 0;
    int y2 = 1;
    for (int j = 0; j < 2; ++j) {
        pBoard[0][y1].setPiece(new Rook(colour));  // black
        pBoard[1][y1].setPiece(new Knight(colour));
        pBoard[2][y1].setPiece(new Bishop(colour));
        pBoard[3][y1].setPiece(new Queen(colour));
        pBoard[4][y1].setPiece(new King(colour));
        pBoard[5][y1].setPiece(new Bishop(colour));
        pBoard[6][y1].setPiece(new Knight(colour));
        pBoard[7][y1].setPiece(new Rook(colour));
        for (int i = 0; i < 8; ++i) {
            pBoard[i][y2].setPiece(new Pawn(colour));
        }
        y1 = 7;
        y2 = 6;
        colour = "white";
    }
}

void Board::Render() { notifyObservers(); }

void Board::setup_placeP(char piecesType, char x, char y) {
    /*
    int change_x_int = x - 97;
    int change_y_int = 7 - (y - 49);
    if (piecesType == 'k') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new King("black"));
    } else if (piecesType == 'q') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Queen("black"));
    } else if (piecesType == 'b') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Bishop("black"));
    } else if (piecesType == 'r') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Rook("black"));
    } else if (piecesType == 'n') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Knight("black"));
    } else if (piecesType == 'p') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Pawn("black"));
    } else if (piecesType == 'K') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new King("white"));
    } else if (piecesType == 'Q') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Queen("white"));
    } else if (piecesType == 'B') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Bishop("white"));
    } else if (piecesType == 'W') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Rook("white"));
    } else if (piecesType == 'N') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Knight("white"));
    } else if (piecesType == 'P') {
        pBoard[x][y].setRow(x);
        pBoard[x][y].setCol(y);
        pBoard[x][y].setPiece(new Pawn("white"));
    }
    */
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

Tile* Board::getTile(int x, int y) {
    if ((x >= 0 && x <= 8) && (y >= 0 && y <= 8)) {
        return &pBoard[x][y];
    }
    throw invalid_argument("out of range");
    
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pBoard.at(i).pop_back();
        }
        pBoard.pop_back();
    }
}
