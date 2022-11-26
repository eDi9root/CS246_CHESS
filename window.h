#ifndef _WINDOW_H
#define _WINDOW_H
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow
{
    Display *d;
    window w;
    int s;
    GC gc;
    unsigned long colours[10];

public:
    Xwindow(int width = 500, int height = 500);
    Xwindow();
    void fillRectangle(int x, int y, int width, int height, int colour = Black);

    void drawString(int x, int y, std::string msg);
};

#endif