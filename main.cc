#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Chess.h"
#include "Move.h"
#include "Board.h"
#include "Player.h"
using namespace std;

int main() {
    //Board *b;
    string command;
    string player1;
    string player2;
    string setup;
    string piecetype; // store the type of the piece
    string coordinate; // for coordinate
    string colour; // turn?
    //string turn;
    string originpos;
    string newpos;
    while (!cin.eof()) {
        cin >> command;
        if (command == "game") {
            cin >> player1 >> player2;
            if ((player1 == "white-player") || (player2 == "black-player")) {
                Chess->player[0] = "white";
                Chess->player[1] = "black"
            } else if (player1 == "human") {
                if (player2 == "computer[1]") {
                    //...
                }
            }
        } else if (command == "setup") { // consider about input "setup" first
            setup_init();
            cin >> setup;
            while (true) {
                if (setup == "+") {
                    cin >> piecetype >> coordinate;
                    if ((piecetype[0] == 'K' || piecetype[0] == 'Q' || piecetype[0] == 'B' || 
                        piecetype[0] == 'R' || piecetype[0] == 'N' || piecetype[0] == 'P' ||
                        piecetype[0] == 'k' || piecetype[0] == 'q' || piecetype[0] == 'b' || 
                        piecetype[0] == 'r' || piecetype[0] == 'n' || piecetype[0] == 'p') &&
                        ((coordinate[0] >= 'a' && coordinate[0] <= 'h') && 
                        (coordinate[1] >= '1' && coordinate[1] <= '8'))) { // check if the command is valid
                        setup_piceceP(piecetype[0], colour, coordinate[0], coordinate[1]); // from board
                    } else {
                        cout << "invalid setup!" << endl;
                    }
                } else if (command == "-") {
                    //...
                }
            }

        } else if (setup == "move") {
            cin >> originpos >> newpos;
            if ((originpos[0] >= 'a' && originpos[0] <= 'h') && (newpos[0] >= 'a' && newpos[0] <= 'h') &&
                (originpos[1] >= '1' && originpos[1] <= '8') && (newpos[1] >= '1' && newpos[1] <= '8')) {
                    move(originpos[0], originpos[1], newpos[0], newpos[1]); // from ???
                }

        } else if (setup == "=") { // makes the input's turn (i.e. white, black)
            cin >> turn;
            /*
            if (turn == "white") {
                //...
            } else if (turn == "black") {
                //...
            }
            */
        } else if (setup == "redesign") {
                
        } else { // invalid command
            cout << "invalid command!" << endl;
        }
    }
}
