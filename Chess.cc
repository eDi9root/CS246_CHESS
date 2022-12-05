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

void Chess::turnmove() {
    string command[2];
    int x[2] = {
        0,
    };
    int y[2] = {
        0,
    };
    Piece *targetpiece = 0;
    Piece *attackpiece = 0;

    cin >> command[0] >> command[1];  // Command input

    x[0] = command[0][0] - 'a';
    y[0] = 7 - (command[0][1] - '1');  // original coordinate

    x[1] = command[1][0] - 'a';
    y[1] = 7 - (command[1][1] - '1');  // target coordinate

    targetpiece = board.getPiece(x[0], y[0]);
    attackpiece = board.getPiece(x[1], y[1]);

    if (targetpiece == 0) {
        throw invalid_argument("Cannot find piece to move\n");
    } else if (!(targetpiece->check_move(x[1], y[1], x[0], y[0], board))) {
        throw invalid_argument("INVALID MOVEMENT\n");
    } else if (targetpiece->pcolour != colour) {
        throw invalid_argument("Not your turn\n");
    } else {
        board.movement(x[1], y[1], x[0], y[0]);
        if (board.check(colour, board) ==
            true) {  // if I moved my king and it made my king in check
            board.movement(x[0], y[0], x[1], y[1]);
            cout << "INVALID MOVEMENT" << endl;
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
                    end_game = false;
                    if (colour == 0) {
                        cout << "Checkmate! Black wins!" << endl;
                    } else {
                        cout << "Checkmate! White wins!" << endl;
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
}

void Chess::setup() {}

void Chess::run() {
    end_game = true;
    string move;
    graphics();
    board.Render();
    cout << "3. move [start_tile] [end_tile]" << endl;
    cout << "4. resign" << endl;
    while (cin >> move) {
        if (move == "move") {
            turnmove();
            board.Render();
            cout << "3. move [start_tile] [end_tile]" << endl;
            cout << "4. resign" << endl;
        } else if (move == "resign") {
            if (colour == 1) {
                cout << "Black resigned this game" << endl;
                cout << "White get one point!" << endl;
            } else {
                cout << "White resigned this game" << endl;
                cout << "Black get one point!" << endl;
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
