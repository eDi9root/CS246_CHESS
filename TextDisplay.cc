#include "TextDisplay.h"

#include <iostream>
#include <string>
using namespace std;

void TextDisplay::notify() {
  for (int i = 8; i > 0; --i) {
    cout << i << " ";
    for (int j = 8; j > 0; --j) {
      cout << subject->getTile(i, j);
    }
    cout << "\n";
  }
}

TextDisplay::TextDisplay(Board *sub) : subject{sub} { subject->attach(this); }

TextDisplay::~TextDisplay() { subject->detach(this); }
