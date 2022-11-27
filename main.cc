#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string command;
    string setup;
    string picecetype;
    string coordinator;
    while (!cin.eof()) {
        cin >> command;
        if (command == "setup") { // consider about input "setup" first
            cin >> setup;
            if (setup == "+") {
                cin >> piecetype >> coordinator;
            }

        }
    }
}
