#include "consts.h"
#include "screen.h"

Screen::Screen() {
    vidptr = (unsigned char*)0xb8000;
    current_loc = 0;
}

void Screen::printString(const char* str) {
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x02;  // Color attribute
    }
}

void Screen::printSymbol(char c) {
    vidptr[current_loc++] = c;
    vidptr[current_loc++] = 0x02;
}

void Screen::printNewLine() {
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
    current_loc = current_loc + (line_size - current_loc % line_size);
}

void Screen::printDeleteSymbol() {
	vidptr[--current_loc] = 0x07;
	vidptr[--current_loc] = ' ';
}

void Screen::printTab() {
    for (int i = 0; i < 4; ++i) {
        printSymbol(' ');
    }
}

void Screen::clearScreen() {
    for (unsigned int i = 0; i < SCREENSIZE; i += 2) {
        vidptr[i] = ' ';
        vidptr[i + 1] = 0x07;
    }
    current_loc = 0;
}


