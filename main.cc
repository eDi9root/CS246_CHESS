
#include <iostream>
#include <sstream>
#include <string>

#include "Chess.h"

using namespace std;

int main() {
    string command;
    string player1;
    string player2;
    string setup;
    string colour;   
    string originpos;
    string newpos;
    bool playing = false;

    float white_win = 0;
    float black_win = 0;
    Chess play = Chess();

    while (!cin.eof()) {
        cout << "Commands" << endl;
        cout << "1. game [white-player] [black-player]" << endl;
        cout << "2. setup" << endl;
        cin >> command;
        if (command == "game") {
            if (playing == false) {
                play.initializeBoard();
            }
            cin >> player1 >> player2;
            play.get_players(player1, player2);
            if (player1 == "human" && player2 == "human") {  // human vs human
                play.run();
            } else if (player1 == "computer[1]" && player2 == "human") {
                play.run_computer(player1, player2);
            } else if (player1 == "human" && player2 == "computer[1]") {
                play.run_computer(player1, player2);
            } else if (player1 == "computer[2]" && player2 == "human") {
                play.run_computer(player1, player2);
            }
        } else if (command == "setup") {  // consider about input "setup" first           
            playing = true;
            play.setupMode();
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
