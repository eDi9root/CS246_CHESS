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

void Board::init() {  // board initialize when the game is started without setup
    int colour = Piece::black;
    int y1 = 0;
    int y2 = 1;
    for (int j = 0; j < 2; ++j) {
        pBoard[0][y1] = new Rook(colour);
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

void Board::setup(char piece, int x, int y) {
    if (piece == 'K') {
        pBoard[x][y] = new King(Piece::white);
    } else if (piece == 'R') {
        pBoard[x][y] = new Rook(Piece::white);
    } else if (piece == 'N') {
        pBoard[x][y] = new Knight(Piece::white);
    } else if (piece == 'B') {
        pBoard[x][y] = new Bishop(Piece::white);
    } else if (piece == 'Q') {
        pBoard[x][y] = new Queen(Piece::white);
    } else if (piece == 'P') {
        pBoard[x][y] = new Pawn(Piece::white);
    } else if (piece == 'k') {
        pBoard[x][y] = new King(Piece::black);
    } else if (piece == 'r') {
        pBoard[x][y] = new Rook(Piece::black);
    } else if (piece == 'n') {
        pBoard[x][y] = new Knight(Piece::black);
    } else if (piece == 'b') {
        pBoard[x][y] = new Bishop(Piece::black);
    } else if (piece == 'q') {
        pBoard[x][y] = new Queen(Piece::black);
    } else if (piece == 'p') {
        pBoard[x][y] = new Pawn(Piece::black);
    } else if (piece == '0') {
        pBoard[x][y] = 0;
    }
}

void Board::set_new_blackking_x(int x) { blackKing_x = x; }
void Board::set_new_blackking_y(int y) { blackKing_y = y; }

void Board::set_new_whiteking_x(int x) { whiteKing_x = x; }
void Board::set_new_whiteking_y(int y) { whiteKing_y = y; }

void Board::Render() { notifyObservers(); }

bool Board::movement(int ax, int ay, int bx, int by) {
    // Remove piece if there is a piece in the place to move
    if (pBoard[ax][ay]) {
        delete pBoard[ax][ay];
    }
    // movement
    pBoard[ax][ay] = pBoard[bx][by];

    // After complete movement, make the original place to zero
    pBoard[bx][by] = 0;

    return true;
}

Piece* Board::getPiece(int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return pBoard[x][y];
    }
    throw string("out of range!");
}

const Piece* Board::getPiece(int x, int y) const {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return pBoard[x][y];
    }
    throw string("out of range");
}

bool Board::stalemate(int colour, Board& board) {
    for (int i = 0; i < 8;
         ++i) {  // check if there's at least one piece that is able to move
        for (int j = 0; j < 8; ++j) {
            if (getPiece(i, j) != 0 &&
                getPiece(i, j)->getColor() ==
                    colour) {  // if it's white's turn check if white is in
                               // stalemate
                for (int k = 0; k < 8; ++k) {  // if it's black's turn check if
                                               // black is in stalemate
                    for (int l = 0; l < 8; ++l) {
                        if (getPiece(i, j)->check_move(k, l, i, j, board) ==
                            true) {
                            Piece* orig = getPiece(i, j);
                            if (getPiece(k, l) != 0) {
                                Piece* change = getPiece(k, l);
                                movement(k, l, i, j);
                                if (check(colour, board) == false) {
                                    delete pBoard[i][j];
                                    delete pBoard[k][l];
                                    pBoard[i][j] = orig;
                                    pBoard[k][l] = change;
                                    return false;
                                } else {
                                    delete pBoard[i][j];
                                    delete pBoard[k][l];
                                    pBoard[i][j] = orig;
                                    pBoard[k][l] = change;
                                }
                            } else {
                                movement(k, l, i, j);
                                if (check(colour, board) == false) {
                                    pBoard[i][j] = orig;
                                    pBoard[k][l] = 0;
                                    return false;
                                } else {
                                    pBoard[i][j] = orig;
                                    pBoard[k][l] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Board::checkmate(int colour) {
    if (colour == 0) {  // just checked if the white is in check
        if (whiteKing_x + 1 < 8) {
            if (getPiece(whiteKing_x + 1, whiteKing_y) != 0) {
                return false;
            }
            if (whiteKing_y - 1 >= 0) {
                if (getPiece(whiteKing_x + 1, whiteKing_y - 1) != 0) {
                    return false;
                }
            }
            if (whiteKing_y + 1 < 8) {
                if (getPiece(whiteKing_x + 1, whiteKing_y + 1) != 0) {
                    return false;
                }
            }
        }
        if (whiteKing_x - 1 >= 0) {
            if (getPiece(whiteKing_x - 1, whiteKing_y) != 0) {
                return false;
            }
            if (whiteKing_y - 1 >= 0) {
                if (getPiece(whiteKing_x - 1, whiteKing_y - 1) != 0) {
                    return false;
                }
            }
            if (whiteKing_y + 1 < 8) {
                if (getPiece(whiteKing_x - 1, whiteKing_y + 1) != 0) {
                    return false;
                }
            }
        }
        if (whiteKing_y + 1 < 8) {
            if (getPiece(whiteKing_x, whiteKing_y + 1) != 0) {
                return false;
            }
        }
        if (whiteKing_y - 1 >= 0) {
            if (getPiece(whiteKing_x, whiteKing_y - 1) != 0) {
                return false;
            }
        }
    } else if (colour == 1) {  // just checked if the white is in check
        if (blackKing_x + 1 < 8) {
            if (getPiece(blackKing_x + 1, blackKing_y) != 0) {
                return false;
            }
            if (blackKing_y - 1 >= 0) {
                if (getPiece(blackKing_x + 1, blackKing_y - 1) != 0) {
                    return false;
                }
            }
            if (blackKing_y + 1 < 8) {
                if (getPiece(blackKing_x + 1, blackKing_y + 1) != 0) {
                    return false;
                }
            }
        }
        if (blackKing_x - 1 >= 0) {
            if (getPiece(blackKing_x - 1, blackKing_y) != 0) {
                return false;
            }
            if (whiteKing_y - 1 >= 0) {
                if (getPiece(blackKing_x - 1, blackKing_y - 1) != 0) {
                    return false;
                }
            }
            if (blackKing_y + 1 < 8) {
                if (getPiece(blackKing_x - 1, blackKing_y + 1) != 0) {
                    return false;
                }
            }
        }
        if (blackKing_y + 1 < 8) {
            if (getPiece(blackKing_x, blackKing_y + 1) != 0) {
                return false;
            }
        }
        if (blackKing_y - 1 >= 0) {
            if (getPiece(blackKing_x, blackKing_y - 1) != 0) {
                return false;
            }
        }
    }
    /*
    if (colour == 0) {
        cout << "Checkmate! Black wins!" << endl;
    } else if (colour == 1) {
        cout << "Checkmate! White wins!" << endl;
    }
    */
    return true;
}

bool Board::check(int colour, Board& board) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board.getPiece(i, j) != 0) {
                if (colour == 0) {  // white, check if white king is in check
                    if (board.getPiece(i, j)->getColor() == Piece::black &&
                        board.getPiece(i, j)->check_move(
                            whiteKing_x, whiteKing_y, i, j, board) == true) {
                        // cout << "White is in check" << endl;
                        return true;
                    }
                } else {
                    if (board.getPiece(i, j)->getColor() == Piece::white &&
                        board.getPiece(i, j)->check_move(
                            blackKing_x, blackKing_y, i, j, board) == true) {
                        // cout << "Black is in check" << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
