#include "PiecesType.h"

#include <iostream>

#include "Piece.h"
using namespace std;

#define abs(x) ((x) < 0 ? -(x) : (x))

King::King(int colour) : Piece(Piece::King, colour) {}

bool King::check_ally(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            return false;
        }
    }
    return true;
}

bool King::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (!(check_ally(ax, ay, bx, by, board))) {
        return false;
    }

    // only can move one tile, possible 8 movement
    if ((abs(bx - ax) > 1 || abs(by - ay) > 1)) {
        return false;
    }

    return Piece::check_move(ax, ay, bx, by, board);
}

Queen::Queen(int colour) : Piece(Piece::Queen, colour) {}

bool Queen::check_ally(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            return false;
        }
    }
    return true;
}

bool Queen::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (!(check_ally(ax, ay, bx, by, board))) {
        return false;
    }

    if (bx != ax && by != ay) {  // can move vertical, horizontal, diagonal
        if (abs(bx - ax) != abs(by - ay)) {
            return false;
        }
    }

    if (ax == bx) {  // Vertical check
        if (by < ay) {
            for (int i = by + 1; i < ay; i++) {
                if ((board.getPiece(bx, i)) != 0) {
                    return false;
                }
            }
        } else if (by > ay) {
            for (int i = by - 1; i > ay; i--) {
                if ((board.getPiece(bx, i)) != 0) {
                    return false;
                }
            }
        }
    } else if (ay == by) {  // horizontal check
        if (bx < ax) {
            for (int i = bx + 1; i < ax; i++) {
                if ((board.getPiece(i, by)) != 0) {
                    return false;
                }
            }
        } else if (bx > ax) {
            for (int i = bx - 1; i > ax; i--) {
                if ((board.getPiece(i, by)) != 0) {
                    return false;
                }
            }
        }
    }
    if (ax > bx && ay > by) {  // diagonal down-right
        int BY = by + 1;
        for (int i = bx + 1; i < ax; i++) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY++;
        }
    } else if (ax < bx && ay > by) {  // diagonal down-left
        int BY = by + 1;
        for (int i = bx - 1; i > ax; i--) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY++;
        }
    } else if (ax < bx && ay < by) {  // diagonal up-left
        int BY = by - 1;
        for (int i = bx - 1; i > ax; i--) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY--;
        }
    } else if (ax > bx && ay < by) {  // diagonal up-right
        int BY = by - 1;
        for (int i = bx + 1; i > ax; i++) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY--;
        }
    }

    return Piece::check_move(ax, ay, bx, by, board);
}

Bishop::Bishop(int colour) : Piece(Piece::Bishop, colour) {}

bool Bishop::check_ally(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            return false;
        }
    }
    return true;
}

bool Bishop::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (!(check_ally(ax, ay, bx, by, board))) {
        return false;
    }

    if (abs(ax - bx) != abs(ay - by)) {  // diagonal movement only
        return false;
    }

    if (ax > bx && ay > by) {  // diagonal down-right
        int BY = by + 1;
        for (int i = bx + 1; i < ax; i++) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY++;
        }
    } else if (ax < bx && ay > by) {  // diagonal down-left
        int BY = by + 1;
        for (int i = bx - 1; i > ax; i--) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY++;
        }
    } else if (ax < bx && ay < by) {  // diagonal up-left
        int BY = by - 1;
        for (int i = bx - 1; i > ax; i--) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY--;
        }
    } else if (ax > bx && ay < by) {  // diagonal up-right
        int BY = by - 1;
        for (int i = bx + 1; i > ax; i++) {
            if ((board.getPiece(i, BY)) != 0) {
                return false;
            }
            BY--;
        }
    }

    return Piece::check_move(ax, ay, bx, by, board);
}

Rook::Rook(int colour) : Piece(Piece::Rook, colour) {}

bool Rook::check_ally(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            return false;
        }
    }
    return true;
}

bool Rook::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (!(check_ally(ax, ay, bx, by, board))) {
        return false;
    }

    if (!(bx == ax || by == ay)) {  // vertical, horizontal movement only
        return false;
    }

    if (ax == bx) {  // Vertical check
        if (by < ay) {
            for (int i = by + 1; i < ay; i++) {
                if ((board.getPiece(bx, i)) != 0) {
                    return false;
                }
            }
        } else if (by > ay) {
            for (int i = by - 1; i > ay; i--) {
                if ((board.getPiece(bx, i)) != 0) {
                    return false;
                }
            }
        }
    } else if (ay == by) {  // horizontal check
        if (bx < ax) {
            for (int i = bx + 1; i < ax; i++) {
                if ((board.getPiece(i, by)) != 0) {
                    return false;
                }
            }
        } else if (bx > ax) {
            for (int i = bx - 1; i > ax; i--) {
                if ((board.getPiece(i, by)) != 0) {
                    return false;
                }
            }
        }
    }

    return Piece::check_move(ax, ay, bx, by, board);
}

Knight::Knight(int colour) : Piece(Piece::Knight, colour) {}

bool Knight::check_ally(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            return false;
        }
    }
    return true;
}

bool Knight::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (!(check_ally(ax, ay, bx, by, board))) {
        return false;
    }

    if (abs(bx - ax) == 1) {  // Special Knight movement
        if (abs(by - ay) == 2) {
            return Piece::check_move(ax, ay, bx, by, board);
        }
    } else if (abs(bx - ax) == 2) {
        if (abs(by - ay) == 1) {
            return Piece::check_move(ax, ay, bx, by, board);
        }
    }
    return false;
}

Pawn::Pawn(int colour) : Piece(Piece::Pawn, colour) {}

bool Pawn::check_ally(int ax, int ay, int bx, int by, Board &board) const {
    if (board.getPiece(ax, ay) != 0) {  // Same colour
        if ((board.getPiece(bx, by)->getColor()) ==
            board.getPiece(ax, ay)->getColor()) {
            return false;
        }
    }
    return true;
}

bool Pawn::check_move(int ax, int ay, int bx, int by, Board &board) const {
    if (!(check_ally(ax, ay, bx, by, board))) {
        return false;
    }

    if (board.getPiece(ax, ay) == 0 && (abs(bx - ax) != abs(by - ay))) {
        if (abs(ax - bx) != 0) {
            return false;
        } else if (abs(by - ay) == 2) {
            if (init_moved) {
                return false;
            }
            if (ax == bx) {  // Vertical check
                if (by < ay) {
                    for (int i = by + 1; i < ay; i++) {
                        if ((board.getPiece(bx, i)) != 0) {
                            return false;
                        }
                    }
                } else if (by > ay) {
                    for (int i = by - 1; i > ay; i--) {
                        if ((board.getPiece(bx, i)) != 0) {
                            return false;
                        }
                    }
                }
            }
        } else if (abs(by - ay) > 2) {  // cannot move over two steps
            return false;
        }
    } else if (board.getPiece(ax, ay) != 0) {  // When attack
        if (abs(bx - ax) != abs(by - ay)) {
            return false;
        } else if (abs(by - ay) != 1) {
            return false;
        }
    } else if (board.getPiece(ax, ay) == 0 && (abs(bx - ax) == abs(by - ay))) {
        return false;
    }

    if (pcolour == Piece::black) {  // cannot go back
        if (!(by - ay < 0)) {
            return false;
        }
    } else if (pcolour == Piece::white) {  // cannot go back
        if (!(by - ay > 0)) {
            return false;
        }
    }
    board.getPiece(bx, by)->init_move();
    return Piece::check_move(ax, ay, bx, by, board);
}
