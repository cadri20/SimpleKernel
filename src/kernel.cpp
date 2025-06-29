#include "keyboard_map.h"
#include "idt.h"
#include "keyboard.h"
#include "screen.h"
#include "consts.h"

extern Screen *screen;

extern "C" void load_gdt();
extern "C" void kmain(void)
{
	const char *str = "Kernel v0.3";
	Screen screenInstance;
	screen = &screenInstance;

	screen->clearScreen();
	screen->printString(str);
	screen->printNewLine();
	screen->printNewLine();

	load_gdt();
	screen->printString("GDT loaded");
	screen->printNewLine();
	idt_init();
	screen->printString("IDT loaded");
	screen->printNewLine();
	keyboard_init();
	screen->printString("Keyboard initialized");
	screen->printNewLine();
	while(1);
}
