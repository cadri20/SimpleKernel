#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "consts.h"
#include "screen.h"
#include "keymap.h"

void keyboard_init(void);
extern "C" void keyboard_handler_main(void);

#endif
