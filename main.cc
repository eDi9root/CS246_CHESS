#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Move.h"
#include "Board.h"
#include "Player.h"
using namespace std;

int main() {
    //Board *b;
    string command;
    string setup;
    string picecetype; // store the type of the piece
    string coordinate; // for coordinate
    string colour; // turn?
    //string turn;
    string originpos;
    string newpos;
    while (!cin.eof()) {
        cin >> command;
        if (command == "setup") { // consider about input "setup" first
            cin >> setup;
            if (setup == "+") {
                cin >> piecetype >> coordinate;
                if ((picecetype[0] == 'K' || picecetype[0] == 'Q' || picecetype[0] == 'B' || 
                     picecetype[0] == 'R' || picecetype[0] == 'N' || picecetype[0] == 'P' ||
                     picecetype[0] == 'k' || picecetype[0] == 'q' || picecetype[0] == 'b' || 
                     picecetype[0] == 'r' || picecetype[0] == 'n' || picecetype[0] == 'p') &&
                    ((coordinate[0] >= 'a' && coordinate[0] <= 'h') && 
                     (coordinate[1] >= '1' && coordinate[1] <= '8'))) { // check if the command is valid
                     setup_piceceP(picecetype[0], colour, coordinate[0], coordinate[1]); // from board
                } else {
                        cout << "invalid setup!" << endl;
                }
            }
        } else if (command == "-") {
                // 하나만 입력받음 (위치)
        } else if (setup == "move") {
            cin >> originpos >> newpos;
            if ((originpos[0] >= 'a' && originpos[0] <= 'h') && (newpos[0] >= 'a' && newpos[0] <= 'h') &&
                (originpos[1] >= '1' && originpos[1] <= '8') && (newpos[1] >= '1' && newpos[1] <= '8')) {
                    move(originpos[0], originpos[1], newpos[0], newpos[1]) // from ???
                }

        } else if (setup == "=") { // makes the input's turn (i.e. white, black)
            cin >> turn;
            if (turn == "white") {
                //...
            } else if (turn == "black") {
                //...
            }
        } else if (setup == "redesign") {
                
        } else { // invalid command
            cout << "invalid command!" << endl;
        }
    }
}
