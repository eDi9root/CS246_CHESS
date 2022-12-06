#include "Chess.h"

#include "TextDisplay.h"

using namespace std;

Chess::Chess() {}

void Chess::initializeBoard() { board.init(); }

void Chess::count_winner(int colour) {
    if (colour == 0) {  // white wins
        winner_white = 1;
    } else if (colour == 1) {  // Black wins
        winner_black = 1;
    }
}

void Chess::count_draw(int colour) {  // draw, stalemate
    winner_white = 0.5;
    winner_black = 0.5;
}

int Chess::printW() { return winner_white; }
int Chess::printB() { return winner_black; }

bool Chess::turnmove() {
    // if (board.stalemate(colour, board) == true) {
    //     return true;
    // }

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

void Chess::run_computer(string player1, string player2) {
    string move;
    bool end_game = false;
    graphics();
    board.Render();
    if (player1 == "computer[1]") {
        while (true) {
            Computers level1 = Computers(1, colour, board);
            colour = !colour;
            board.Render();
            cout << "3. move [start_tile] [end_tile]" << endl;
            cout << "4. resign" << endl;
            while (cin >> move) {
                if (move == "move") {
                    if (turnmove()) {
                        end_game = true;
                    }
                    board.Render();
                    break;
                } else if (move == "resign") {
                    if (colour == 1) {
                        cout << "White wins!" << endl;
                    } else {
                        cout << "Black wins!" << endl;
                    }
                    count_winner(!(colour));
                    end_game = true;
                    break;
                } else {
                    cout << "Invalid Command!" << endl;
                }
            }
            if (end_game) {
                break;
            }
        }
    } else if (player2 == "computer[1]") {
        bool isresign = false;
        while (true) {
            cout << "3. move [start_tile] [end_tile]" << endl;
            cout << "4. resign" << endl;
            while (cin >> move) {
                if (move == "move") {
                    if (turnmove()) {
                        end_game = true;
                    }
                    board.Render();
                    break;
                } else if (move == "resign") {
                    if (colour == 1) {
                        cout << "White wins!" << endl;
                    } else {
                        cout << "Black wins!" << endl;
                    }
                    count_winner(!(colour));
                    end_game = true;
                    isresign = true;
                    break;
                } else {
                    cout << "Invalid Command!" << endl;
                }
            }
            if (!(isresign)) {
                Computers level1 = Computers(1, colour, board);
                colour = !colour;
                board.Render();
            }
            if (end_game) {
                break;
            }
        }

    } else if (player1 == "computer[2]") {
        while (true) {
            Computers level2 = Computers(2, colour, board);
            colour = !colour;
            board.Render();
            cout << "3. move [start_tile] [end_tile]" << endl;
            cout << "4. resign" << endl;
            while (cin >> move) {
                if (move == "move") {
                    if (turnmove()) {
                        end_game = true;
                    }
                    board.Render();
                    break;
                } else if (move == "resign") {
                    if (colour == 1) {
                        cout << "White wins!" << endl;
                    } else {
                        cout << "Black wins!" << endl;
                    }
                    count_winner(!(colour));
                    end_game = true;
                    break;
                } else {
                    cout << "Invalid Command!" << endl;
                }
            }
            if (end_game) {
                break;
            }
        }
    }
}
void Chess::blackKing() { cntblackKing = 1; }
void Chess::whiteKing() { cntwhiteKing = 1; }

void Chess::setupMode() {
    string setup;
    string piecetype;   // store the type of the piece
    string coordinate;  // for coordinate
    string turn;
    graphics();
    board.Render();
    while (cin >> setup) {
        if (setup == "+") {
            cin >> piecetype >> coordinate;
            if ((piecetype[0] == 'K' || piecetype[0] == 'Q' ||
                 piecetype[0] == 'B' || piecetype[0] == 'R' ||
                 piecetype[0] == 'N' || piecetype[0] == 'P' ||
                 piecetype[0] == 'k' || piecetype[0] == 'q' ||
                 piecetype[0] == 'b' || piecetype[0] == 'r' ||
                 piecetype[0] == 'n' || piecetype[0] == 'p') &&
                ((coordinate[0] >= 'a' && coordinate[0] <= 'h') &&
                 (coordinate[1] >= '1' && coordinate[1] <= '8'))) {
                int x = coordinate[0] - 'a';
                int y = 7 - (coordinate[1] - '1');
                // check if the command is valid
                if (piecetype[0] == 'K') {
                    if (cntwhiteKing == 0) {
                        board.setup(piecetype[0], x, y);
                        whiteKing();
                        board.set_new_whiteking_x(x);
                        board.set_new_whiteking_y(y);
                        board.Render();
                        continue;
                    } else {
                        cout << "You already place the White king" << endl;
                        continue;
                    }
                    continue;
                } else if (piecetype[0] == 'k') {
                    if (cntblackKing == 0) {
                        board.setup(piecetype[0], x, y);
                        blackKing();
                        board.set_new_blackking_x(x);
                        board.set_new_blackking_y(y);
                        board.Render();
                        continue;
                    } else {
                        cout << "You already place the Black king" << endl;
                        continue;
                    }
                    continue;
                } else if ((piecetype[0] == 'P' || piecetype[0] == 'p') &&
                           (y == 0 || y == 7)) {
                    cout << "You can't place pawn on the first and last row"
                         << endl;
                    continue;
                } else {
                    board.setup(piecetype[0], x, y);
                    board.Render();
                    continue;
                }
            } else {
                cout << "Invalid Command" << endl;
                continue;
            }
        } else if (setup == "-") {
            cin >> coordinate;
            int x = coordinate[0] - 'a';
            int y = 7 - (coordinate[1] - '1');
            board.setup('0', x, y);
            if (x == board.blackKing_x && y == board.blackKing_y) {
                board.set_new_blackking_x(-1);
                board.set_new_blackking_y(-1);
            } else if (x == board.whiteKing_x && y == board.whiteKing_y) {
                board.set_new_whiteking_x(-1);
                board.set_new_whiteking_y(-1);
            }
            board.Render();
            continue;
        } else if (setup == "=") {
            cin >> turn;
            if (turn == "black") {
                colour = !colour;
            }
            continue;
        } else if (setup == "done") {
            if (cntblackKing == 1 && cntwhiteKing == 1) {
                if (board.check(0, board) == false &&
                    board.check(1, board) == false) {
                    cout << "ready for start playing the game:)" << endl;
                    break;
                }
            } else {
                cout << "You can't finish the setup mode" << endl;
                continue;
            }
        } else {
            cout << "Invalid Command" << endl;
            continue;
        }
    }
}

void Chess::graphics() {
    unique_ptr<Observer> o;
    o = std::make_unique<TextDisplay>(&board);
    ob.push_back(std::move(o));
}

void Chess::get_players(string p1, string p2) {
    player1 = p1;
    player2 = p2;
}
