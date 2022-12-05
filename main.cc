
#include <iostream>
#include <sstream>
#include <string>

#include "Chess.h"
#include "Player.h"

using namespace std;

int main() {
    string command;
    string player1;
    string player2;
    string setup;
    string piecetype;   // store the type of the piece
    string coordinate;  // for coordinate
    string colour;      // turn?
    string turn;
    string originpos;
    string newpos;

    float white_win = 0;
    float black_win = 0;

    while (!cin.eof()) {
        Chess play = Chess();
        cout << "Commands" << endl;
        cout << "1. game [white-player] [black-player]" << endl;
        cout << "2. setup" << endl;
        cin >> command;
        if (command == "game") {
            cin >> player1 >> player2;
            if (player1 == "human" && player2 == "human") {
                play.run();
            }
        } else if (command == "setup") {  // consider about input "setup" first
            // setup_init();
            cin >> setup;
            while (true) {
                if (setup == "+") {
                    cin >> piecetype >> coordinate;
                    if ((piecetype[0] == 'K' || piecetype[0] == 'Q' ||
                         piecetype[0] == 'B' || piecetype[0] == 'R' ||
                         piecetype[0] == 'N' || piecetype[0] == 'P' ||
                         piecetype[0] == 'k' || piecetype[0] == 'q' ||
                         piecetype[0] == 'b' || piecetype[0] == 'r' ||
                         piecetype[0] == 'n' || piecetype[0] == 'p') &&
                        ((coordinate[0] >= 'a' && coordinate[0] <= 'h') &&
                         (coordinate[1] >= '1' &&
                          coordinate[1] <=
                              '8'))) {  // check if the command is valid

                    } else {
                        cout << "invalid setup!" << endl;
                    }
                } else {
                    cout << "invalid input!" << endl;
                    /*
                  } else if (command == "-") {
                    //...
                  }
                  */
                }
            }
            /*
                    } else if (command == "move") {
                        cin >> originpos >> newpos;
                        if ((originpos[0] >= 'a' && originpos[0] <= 'h') &&
                            (newpos[0] >= 'a' && newpos[0] <= 'h') &&
                            (originpos[1] >= '1' && originpos[1] <= '8') &&
                            (newpos[1] >= '1' && newpos[1] <= '8')) {
                            cout << "move" << endl;
                            // move(originpos[0], originpos[1], newpos[0],
               newpos[1]);  //
                            // from ???
                        }
            */
        } else if (command ==
                   "=") {  // makes the input's turn (i.e. white, black)
            cin >> turn;
            /*
            if (turn == "white") {
                //...
            } else if (turn == "black") {
                //...
            }
            */
        } else {  // invalid command
            cout << "invalid command!" << endl;
        }
        white_win = white_win + play.printW();
        black_win = black_win + play.printB();
    }
    cout << "Final Score: " << endl;
    cout << "White: " << white_win << endl;
    cout << "Black: " << black_win << endl;
}
