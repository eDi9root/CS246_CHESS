#include "PiecesType.h"

#include <iostream>

#include "Piece.h"
using namespace std;

#define abs(x) ((x) < 0 ? -(x) : (x))

King::King(int colour) : Piece(Piece::King, colour) {}

bool King::check_move(int ax, int ay, int bx, int by, Board &board) const {
    // 한칸씩 이동 가능
    if (ax >= bx - 1 && ax <= bx + 1) {
        if (ay >= by - 1 && ay <= by + 1) {
            return Piece::check_move(ax, ay, bx, by, board);
        }
    }
    return false;
}

Queen::Queen(int colour) : Piece(Piece::Queen, colour) {}

bool Queen::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            cout << "There is an ally" << endl;
            return false;
        }
    }
    if (ax == bx) {  // Vertical check
        if (by < ay) {
            for (int i = by + 1; i < ay; i++) {
                if ((board.getPiece(bx, i)) != 0) {
                    cout << "Blocked" << endl;
                    return false;
                }
            }
        } else if (by > ay) {
            for (int i = by - 1; i > ay; i--) {
                if ((board.getPiece(bx, i)) != 0) {
                    cout << "Blocked" << endl;
                    return false;
                }
            }
        }
    } else if (ay == by) {  // horizontal check
        if (bx < ax) {
            for (int i = bx + 1; i < ax; i++) {
                if ((board.getPiece(i, by)) != 0) {
                    cout << "Blocked" << endl;
                    return false;
                }
            }
        } else if (bx > ax) {
            for (int i = bx - 1; i > ax; i--) {
                if ((board.getPiece(i, by)) != 0) {
                    cout << "Blocked" << endl;
                    return false;
                }
            }
        }
    }
    if (ax > bx && ay > by) {  // diagonal down-right
        int BY = by + 1;
        for (int i = bx + 1; i < ax; i++) {
            if ((board.getPiece(i, BY)) != 0) {
                cout << "Blocked1" << endl;
                return false;
            }
            BY++;
        }
    } else if (ax < bx && ay > by) {  // diagonal down-left
        int BY = by + 1;
        for (int i = bx - 1; i > ax; i--) {
            if ((board.getPiece(i, BY)) != 0) {
                cout << "Blocked2" << endl;
                return false;
            }
            BY++;
        }
    } else if (ax < bx && ay < by) {  // diagonal up-left
        int BY = by - 1;
        for (int i = bx - 1; i > ax; i--) {
            if ((board.getPiece(i, BY)) != 0) {
                cout << "Blocked3" << endl;
                return false;
            }
            BY--;
        }
    } else if (ax > bx && ay < by) {  // diagonal up-right
        int BY = by - 1;
        for (int i = bx + 1; i > ax; i++) {
            if ((board.getPiece(i, BY)) != 0) {
                cout << "Blocked4" << endl;
                return false;
            }
            BY--;
        }
    }

    if (bx != ax && by != ay) {
        if (abs(bx - ax) != abs(by - ay)) {
            cout << "Invalid movement" << endl;
            return false;
        }
    }

    return Piece::check_move(ax, ay, bx, by, board);
}

Bishop::Bishop(int colour) : Piece(Piece::Bishop, colour) {}

bool Bishop::check_move(int ax, int ay, int bx, int by, Board &board) const {
    // bishop은 대각선만
    if (abs(ax - bx) == abs(ay - by)) {
        return Piece::check_move(ax, ay, bx, by, board);
    }
    return false;
}

Rook::Rook(int colour) : Piece(Piece::Rook, colour) {}

bool Rook::check_move(int ax, int ay, int bx, int by, Board &board) const {
    // 룩은 직선만
    if (ax == bx) {
        return Piece::check_move(ax, ay, bx, by, board);
    } else if (ay == by) {
        return Piece::check_move(ax, ay, bx, by, board);
    }
    return false;
}

Knight::Knight(int colour) : Piece(Piece::Knight, colour) {}

bool Knight::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (abs(1 - bx) == ax) {
        if (abs(2 - by) == ay) {
            return Piece::check_move(ax, ay, bx, by, board);
        }
    } else if (abs(2 - bx) == ax) {
        if (abs(1 - by) == ay) {
            return Piece::check_move(ax, ay, bx, by, board);
        }
    }
    return false;
}

Pawn::Pawn(int colour) : Piece(Piece::Pawn, colour) {}

bool Pawn::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (pcolour == Piece::black) {
        if (ax == bx && (ay > by && ay - 2 <= by)) {
            return Piece::check_move(ax, ay, bx, by, board);
        }
    } else {
        if (ax == bx && (ay < by && ay + 2 >= by)) {
            return Piece::check_move(ax, ay, bx, by, board);
        }
    }
    return false;
}

bool Pawn::check_attack(int ax, int ay, int bx, int by, Board &board) const {
    if (pcolour == Piece::black) {
        if ((abs(1 + ax) == bx) && (ay - 1 == by)) {
            return true;
        }
    } else {
        if ((abs(1 - ax) == bx) && (ay + 1 == by)) {
            return true;
        }
    }
    return false;
}
