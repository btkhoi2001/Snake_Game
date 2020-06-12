#include "snake.h"
#include "console.h"
#include "menu.h"
#include <iostream>
using namespace std;

int main() {

	ResizeConsole(WIDTH, HEIGHT);
	FixConsoleWindow();
	NoCursorType();
	NoVerticalScrollbar();

	while (true) {
		DrawMenu();

		Sleep(100000000);
	}

	return 0;
}