#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string command;
    string setup;
    string picecetype; // store the type of the piece
    string coordinate; // for coordinate
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
                    ((coordinate[0] >= 'a' && coordinate[0] <= 'z') && 
                     (coordinate[1] >= '1' && coordinate[1] <= '1'))) { // check if the command is valid
                     Board::setup_placeP(picecetype[0], coordinate[0], coordinate[1]);
                }
            } else if (setup == "-") {
                // 하나만 입력받음 (위치)
            }
        }
    }
}
