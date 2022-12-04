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
    int colour = Piece::black;
    int y1 = 0;
    int y2 = 1;
    for (int j = 0; j < 2; ++j) {
        pBoard[0][y1] = new Rook(colour);  // white
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
        colour = Piece::white;
    }
    blackKing_x = 4;
    blackKing_y = 0;
    whiteKing_x = 4;
    whiteKing_y = 7;
}

void Board::set_new_blackking_x(int x) {
    blackKing_x = x;
}
void Board::set_new_blackking_y(int y) {
    blackKing_y = y;
}

void Board::set_new_whiteking_x(int x) {
    whiteKing_x = x;
}
void Board::set_new_whiteking_y(int y) {
    whiteKing_y = y;
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

bool Board::check(int colour) {
    cout << "black king x: " << blackKing_x << ", black king y: " << blackKing_y << endl;
    cout << "white king x: " << whiteKing_x << ", white king y: " << whiteKing_y << endl;
    
    if (colour == 0) { // white
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {

                }

            }
        }
        
        return true;

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


