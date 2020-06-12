#include "menu.h"

// Vẽ viền menu
void DrawBorderMenu() {

	GotoXY(0, 0); cout << TOP_LEFT_BORDER;
	GotoXY(WIDTH_MENU - 1, 0); cout << TOP_RIGHT_BORDER;
	GotoXY(0, HEIGHT_MENU - 1); cout << BOTTOM_LEFT_BORDER;
	GotoXY(WIDTH_MENU - 1, HEIGHT_MENU - 1); cout << BOTTOM_RIGHT_BORDER;

	for (int i = 1; i < WIDTH_MENU - 1; i++) {
		GotoXY(i, 0); cout << WIDTH_MENU_BORDER;
		GotoXY(i, HEIGHT_MENU - 1); cout << WIDTH_MENU_BORDER;
	}

	for (int i = 1; i < HEIGHT_MENU - 1; i++) {
		GotoXY(0, i); cout << HEIGHT_MENU_BORDER;
		GotoXY(WIDTH_MENU - 1, i); cout << HEIGHT_MENU_BORDER;
	}
}

// Vẽ chữ Snake
void DrawSnakeText() {

	ifstream fileInput("text.inp");
	if (fileInput.fail()) {
		cout << "Can not read file";
		Sleep(5000);
		exit(0);
	}

	int line = 1;
	while (!fileInput.eof()) {
		string text;
		getline(fileInput, text);
		SetTextColor(CYAN_COLOR);
		GotoXY(40, line++); cout << text;
	}

	fileInput.close();
}

// Vẽ menu
void DrawMenu() {

	DrawBorderMenu();
	DrawSnakeText();
}