#include "console.h"
#include "menu.h"

int main() {

	ResizeConsole(WIDTH, HEIGHT);
	FixConsoleWindow();
	NoCursorType();
	NoVerticalScrollbar();
	while (true) {
		Clrscr();
		DrawMenu();
		int choice = SelectMenu();
		ActiveSelect(choice);
	}

	return 0;
}