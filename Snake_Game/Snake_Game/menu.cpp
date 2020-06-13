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

	int line = 2;
	SetTextColor(CYAN_COLOR);
	while (!fileInput.eof()) {
		string text;
		getline(fileInput, text);
		GotoXY(40, line++); cout << text;
	}

	fileInput.close();
}

// Vẽ list menu
void DrawListMenu(ListMenu listMenu[]) {

	SetTextColor(DARK_RED_COLOR);
	GotoXY(listMenu[0].x - 4, listMenu[0].y); cout << ">> " << listMenu[0].name;

	SetTextColor(WHITE_COLOR);
	for (int i = 1; i < 4; i++) {
		GotoXY(listMenu[i].x, listMenu[i].y);
		cout << listMenu[i].name;
	}

	GotoXY(42, 20); cout << "press Enter to continue";
}

// Highlight lựa chọn
void HightlightList(ListMenu listMenu[], int& curChoice, int nextChoice) {

	SetTextColor(WHITE_COLOR);
	GotoXY(listMenu[curChoice].x - 4, listMenu[curChoice].y); cout << "               ";
	GotoXY(listMenu[curChoice].x, listMenu[curChoice].y); cout << listMenu[curChoice].name;
	SetTextColor(DARK_RED_COLOR);
	GotoXY(listMenu[nextChoice].x, listMenu[nextChoice].y); cout << "               ";
	GotoXY(listMenu[nextChoice].x - 4, listMenu[nextChoice].y); cout << ">> " << listMenu[nextChoice].name;
	curChoice = nextChoice;
}

// Chọn menu
int SelectMenu() {

	ListMenu listMenu[] = { {"NEW GAME", 48, 11}, {"LOAD GAME", 48, 13}, {"ABOUT", 48, 15}, {"QUIT", 48, 17} };
	DrawListMenu(listMenu);

	int choice = 0;
	int nextChoice = 0;
	while (true) {
		if (_kbhit()) {
			char key = toupper(_getch());
			if (key == 'W') {
				nextChoice = choice == 0 ? 3 : choice - 1;
				HightlightList(listMenu, choice, nextChoice);
			}
			else if (key == 'S') {
				nextChoice = choice == 3 ? 0 : choice + 1;
				HightlightList(listMenu, choice, nextChoice);
			}
			else if (key == char(13)) // Enter 
				return choice;
		}
	}
	return -1;
}

// Vẽ menu
void DrawMenu() {

	DrawBorderMenu();
	DrawSnakeText();
}

// Khởi động lựa chọn
void ActiveSelect(int choice) {

	switch (choice) {
	case 0:
		StartGame();
		break;

	case 3:
		exit(0);
	}
}