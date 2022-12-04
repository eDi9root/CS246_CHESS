#include "PiecesType.h"

#include <iostream>

#include "Piece.h"
using namespace std;

#define abs(x) ((x) < 0 ? -(x) : (x))

King::King(int colour) : Piece(Piece::King, colour) {}

bool King::check_move(int ax, int ay, int bx, int by, Board &board) const {
    // only can move one tile, possible 8 movement
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            cout << "There is an ally" << endl;
            return false;
        }
    }
    if ((abs(bx - ax) > 1 || abs(by - ay) > 1)) {
        cout << "Invalid movement!" << endl;
        return false;
    }
    return Piece::check_move(ax, ay, bx, by, board);
}

Queen::Queen(int colour) : Piece(Piece::Queen, colour) {}

bool Queen::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
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
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            cout << "There is an ally" << endl;
            return false;
        }
    }

    if (abs(ax - bx) != abs(ay - by)) {  // diagonal movement only
        cout << "Invalid movement!!" << endl;
        return false;
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

    return Piece::check_move(ax, ay, bx, by, board);
}

Rook::Rook(int colour) : Piece(Piece::Rook, colour) {}

bool Rook::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            cout << "There is an ally" << endl;
            return false;
        }
    }

    if (!(bx == ax || by == ay)) {
        return false;
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

    return Piece::check_move(ax, ay, bx, by, board);
}

Knight::Knight(int colour) : Piece(Piece::Knight, colour) {}

bool Knight::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            cout << "There is an ally" << endl;
            return false;
        }
    }

    if (abs(1 - bx) == ax) {  // Special Knight movement
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
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            cout << "There is an ally" << endl;
            return false;
        }
    }
    if (pcolour == Piece::black) {
        if (!(ax == bx && (ay > by && ay - 2 <= by))) {
            return false;
        }
    } else {
        if (!(ax == bx && (ay < by && ay + 2 >= by))) {
            return false;
        }
    }

    if (board.getPiece(ax, ay) == 0 && ((bx - ax) != (by - ay))) {
        if (ax != bx) {
            return false;
        } else if ((by - ay == 2) || (ay - by) == 2) {
            if (!(init_two_move)) {
                return false;
            }
            if (ay == by) {  // horizontal check
                if (bx < ax) {
                    for (int i = bx + 1; i < ax; i++) {
                        if ((board.getPiece(i, by)) != 0) {
                            cout << "Blocked Pawn" << endl;
                            return false;
                        }
                    }
                } else if (bx > ax) {
                    for (int i = bx - 1; i > ax; i--) {
                        if ((board.getPiece(i, by)) != 0) {
                            cout << "Blocked Pawn" << endl;
                            return false;
                        }
                    }
                }
            }
            // init_two_move = false;
        } else if ((by - ay > 2) ||
                   (ay - by > 2)) {  // cannot move over two steps
            cout << "Invalid movement pawn" << endl;
            return false;
        }
    } else if (board.getPiece(ax, ay) != 0 &&
               ((bx - ax) == (by - ay))) {  // When attack
        if ((bx - ax) != (by - ay)) {
            cout << "Invalid attack" << endl;
            return false;
        } else if ((by - ay) != 1) {
            cout << "Invalid attack" << endl;
            return false;
        }
    } else if (board.getPiece(ax, ay) == 0 && ((bx - ax) == (by - ay))) {
        return false;
    }
    if (pcolour == Piece::black) {
        if (!(by - ay < 0)) {
            cout << "Cannot go back!" << endl;
            return false;
        }
    } else if (pcolour == Piece::white) {
        if (!(by - ay > 0)) {
            cout << "Cannot go back" << endl;
            return false;
        }
    }
    return Piece::check_move(ax, ay, bx, by, board);
}
