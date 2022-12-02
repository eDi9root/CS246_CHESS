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

void Board::init() {
    int colour = Piece::white;
    int y1 = 0;
    int y2 = 1;
    for (int j = 0; j < 2; ++j) {
        pBoard[y1][0] = new Rook(colour);  // white
        pBoard[y1][1] = new Knight(colour);
        pBoard[y1][2] = new Bishop(colour);
        pBoard[y1][4] = new Queen(colour);
        pBoard[y1][3] = new King(colour);
        pBoard[y1][5] = new Bishop(colour);
        pBoard[y1][6] = new Knight(colour);
        pBoard[y1][7] = new Rook(colour);
        for (int i = 0; i < 8; ++i) {
            pBoard[y2][i] = new Pawn(colour);
        }
        y1 = 7;
        y2 = 6;
        colour = Piece::black;
    }
}

void Board::Render() { notifyObservers(); }

bool Board::movement(int ax, int ay, int bx, int by) {
    // 이동할 곳에 말이 있으면 제거
    if (pBoard[ax][ay]) {
        delete pBoard[ax][ay];
    }
    // 단순히 이동
    pBoard[ax][ay] = pBoard[bx][by];

    // 이동 완료될 경우 지나간 자리는 0 또는 null 로
    pBoard[bx][by] = 0;

    return true;
}

Piece* Board::getPiece(int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return pBoard[x][y];
    }
    throw invalid_argument("!out of range!");
}

const Piece* Board::getPiece(int x, int y) const {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return pBoard[x][y];
    }
    throw invalid_argument("!out of range");
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pBoard[i][j] != 0) {
                delete pBoard[i][j];
            }
        }
    }
}
