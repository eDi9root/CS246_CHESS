#include <iostream>
#include "Piece"
using namespace std;


int Piece::calculate_coord_x(char letter) {
    if (letter == 'a') {
        return 0;
    } else if (letter == 'b') {
        return 1;
    } else if (letter == 'c') {
        return 2;
    } else if (letter == 'd') {
        return 3;
    } else if (letter == 'e') {
        return 4;
    } else if (letter == 'f') {
        return 5;
    } else if (letter == 'g') {
        return 6;
    } else {
        return 7;
    }
}

int Piece::calculate_coord_y(char number) {
    if (number == '1') {
        return 0;
    } else if (number == '2') {
        return 1;
    } else if (number == '3') {
        return 2;
    } else if (number == '4') {
        return 3;
    } else if (number == '5') {
        return 4;
    } else if 

}

bool Piece::getcheck(char origin_x, char origin_y, char new_x, char new_y) const {
    int ax = calculate_coord_x(origin_x);
    int ay = calculate_coord_y(origin_y);
    int bx = 
    //return (!(origin_x < 0 || orgin_x >= 8 || ) )

}
