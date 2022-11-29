#include "Tile.h"
#include <iostream>

Tile::Tile() : row{0}, col{0}, position{"0"}, piecethatisonTile{NULL} {}

bool Tile::get_empty_tile() {
    if (piecethatisonTile == NULL) {
        return true;
    }
    return false;
}

int Tile::getRow() {
    return row;

}

int Tile::getCol() {
    return col;

}
Piece* Tile::getPiece() {
    return piecethatisonTile;

}

string Tile::getPos() {
    return position;
}

Tile::~Tile() {
    delete piecethatisonTile;
}

/*
void Tile::setRow(int x) {
    this->x = row;
}
void Tile::setCol(int y) {
    this->y = col;
}
*/
void Tile::setPos(string pos) {
    position = pos;
    char x_coord = pos[0]; // alphabet
    char y_coord = pos[1]; // number
    int change_x_int = x_coord - 97;
    int change_y_int = 7 - (y_coord - 49);
    row = change_x_int;
    col = change_y_int;
}
void Tile::setPiece(Piece *piece) {
    piecethatisonTile = piece;
}
