#include "Board.h"

#include <iostream>
#include <vector>

#include "PiecesType.h"
#include "TextDisplay.h"
using namespace std;

Board::Board() {
  // 0 으로 초기화
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
    }
  }
}