#ifndef _WINDOW_H
#define _WINDOW_H
#include <X11/Xlib.h>

#include <iostream>
#include <string>

class Xwindow {
    Display* d;
    Window w;
    int s;
    GC gc, gc_2;
    unsigned long colours[10];
    int width, height;

   public:
    enum {
        White = 0,
        Black,
        Red,
        Green,
        Blue,
        Cyan,
        Yellow,
        Magenta,
        Orange,
        Brown
    };
    // colours

   public:
    Xwindow(int width = 800, int height = 800);  // constructor, from the a4
    ~Xwindow();                                  // destructor, from the a4

    void fillRectangle(int x, int y, int width, int height, int colour = Black);

    void drawString(int x, int y, std::string msg, int colour = Black);

    void drawLine(int x1, int x2, int y1, int y2);

    // void drawPiece(int x, int y, int width, int height, char piece);

   private:
    void printMassage(int x, int y, const std::string& msg, int colour,
                      XFontStruct& xf);
};

#endif