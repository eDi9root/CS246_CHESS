#ifndef _TEXTDISPLAY_H
#define _TEXTDISPLAY_H

#include <iostream>
#include <string>
using namespace std;

class TextDisplay {
  char **Tdisplay;

 public:
  void notify(char letter, int row, int col);
  TextDisplay();
  ~TextDisplay();
  friend ostream &operator<<(ostream &out, const TextDisplay &t);
};

#endif
