#include "keyboard.h"

extern "C" void write_port(unsigned short port, unsigned char data);
extern "C" char read_port(unsigned short port);
extern unsigned char keyboard_map[128];
extern Screen *screen;

void keyboard_init(void)
{
    // 0xFD is 11111101 - enables only IRQ1 (keyboard)
	write_port(0x21 , 0xFD);
}

extern "C" void keyboard_handler_main(void)
{
	unsigned char status;
	char keycode;

	// Write EOI
	write_port(0x20, 0x20);

	status = read_port(KEYBOARD_STATUS_PORT);
	// Lowest bit of status will be set if buffer is not empty
	if (status & 0x01) {
		keycode = read_port(KEYBOARD_DATA_PORT);
		if(keycode < 0) {
            return;
        }

		if(keycode == ENTER_KEY_CODE) {
			screen->printNewLine();
			return;
		}
        if(keycode == BACKSPACE_KEY_CODE) {
            screen->printDeleteSymbol();
            return;
        }
        if(keycode == TAB_KEY_CODE) {
            screen->printTab();
            return;
        }

        char input_str = keyboard_map[(unsigned char) keycode];
        screen->printSymbol(input_str);
	}
}
