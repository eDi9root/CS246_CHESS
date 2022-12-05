#include "Chess.h"

#include "TextDisplay.h"

using namespace std;

Chess::Chess() { board.init(); }

void Chess::count_winner(int colour) {
    if (colour == 0) {  // white wins
        winner_white = 1;
    } else if (colour == 1) {
        winner_black = 1;
    }
}

void Chess::count_draw(int colour) {
    winner_white = 0.5;
    winner_black = 0.5;
}

int Chess::printW() { return winner_white; }
int Chess::printB() { return winner_black; }

bool Chess::turnmove() {
    string command[2];
    int x[2] = {
        0,
    };
    int y[2] = {
        0,
    };

    cin >> command[0] >> command[1];  // Command input

    x[0] = command[0][0] - 'a';
    y[0] = 7 - (command[0][1] - '1');  // original coordinate

    x[1] = command[1][0] - 'a';
    y[1] = 7 - (command[1][1] - '1');  // target coordinate

    Piece* targetpiece = 0;

    targetpiece = board.getPiece(x[0], y[0]);
    if (targetpiece == 0) {
        throw string("Cannot find piece to move\n");
    } else if (!(targetpiece->check_move(x[1], y[1], x[0], y[0], board))) {
        throw string("INVALID MOVEMENT\n");
    } else if (targetpiece->pcolour != colour) {
        throw string("Not your turn\n");
    } else {
        board.movement(x[1], y[1], x[0], y[0]);
        if (board.check(colour, board) == true) {
            board.movement(x[0], y[0], x[1], y[1]);
            cout << "INVALID MOVEMENT" << endl;
            // if I moved my Pieces and it made my king in check then
            // cant move
        } else {
            if (board.getPiece(x[1], y[1])->pid == Piece::King) {
                if (board.getPiece(x[1], y[1])->getColor() == Piece::black) {
                    board.set_new_blackking_x(x[1]);
                    board.set_new_blackking_y(y[1]);
                } else {
                    board.set_new_whiteking_x(x[1]);
                    board.set_new_whiteking_y(y[1]);
                }
            }
            colour = !colour;
            if (board.check(colour, board) == true) {
                if (board.checkmate(colour) == true) {
                    count_winner(!(colour));
                    if (colour == 0) {
                        cout << "Checkmate! Black wins!" << endl;
                        return true;
                    } else {
                        cout << "Checkmate! White wins!" << endl;
                        return true;
                    }
                } else {
                    if (colour == 0) {
                        cout << "White is in check" << endl;
                    } else {
                        cout << "Black is in check" << endl;
                    }
                }
            }
        }
    }
    return false;
}

void Chess::setup() {}

void Chess::run() {
    string move;
    graphics();
    board.Render();
    cout << "3. move [start_tile] [end_tile]" << endl;
    cout << "4. resign" << endl;
    while (cin >> move) {
        if (move == "move") {
            try {
                if (turnmove()) {
                    break;
                }
            } catch (string error) {
                cout << error << endl;
                cout << "Try again\n" << endl;
            }
            board.Render();
            cout << "3. move [start_tile] [end_tile]" << endl;
            cout << "4. resign" << endl;
        } else if (move == "resign") {
            if (colour == 1) {
                cout << "White wins!" << endl;
            } else {
                cout << "Black wins!" << endl;
            }
            count_winner(!(colour));
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }
}

void Chess::graphics() {
    unique_ptr<Observer> o;
    o = std::make_unique<TextDisplay>(&board);
    ob.push_back(std::move(o));
}
