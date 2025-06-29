#ifndef SCREEN_H
#define SCREEN_H

#include "consts.h"

extern unsigned int current_loc;

class Screen {
public:

    static const unsigned int VIDEO_MEMORY = 0xB8000;

    Screen();

    void printString(const char* str);
    void printSymbol(char c);
    void printNewLine();
    void printDeleteSymbol();
    void printTab();
    void clearScreen();

private:
    unsigned char* vidptr;
    unsigned int current_loc;
};

#endif
