#include "menu.h"

// Vẽ viền menu
void DrawBorderMenu() {

	SetTextColor(WHITE_COLOR);
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

	ifstream fileInput("text.txt");
	if (fileInput.fail()) {
		cout << "File does not exist";
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
void DrawListMenu(vector <List> listMenu) {

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
void HightlightList(vector <List> listMenu, int& curChoice, int nextChoice) {

	SetTextColor(WHITE_COLOR);
	GotoXY(listMenu[curChoice].x - 4, listMenu[curChoice].y); cout << "                        ";
	GotoXY(listMenu[curChoice].x, listMenu[curChoice].y); cout << listMenu[curChoice].name;
	SetTextColor(DARK_RED_COLOR);
	GotoXY(listMenu[nextChoice].x, listMenu[nextChoice].y); cout << "                        ";
	GotoXY(listMenu[nextChoice].x - 4, listMenu[nextChoice].y); cout << ">> " << listMenu[nextChoice].name;
	curChoice = nextChoice;
}

// Chọn menu
int SelectMenu() {

	vector <List> listMenu = { {"NEW GAME", 48, 11}, {"LOAD GAME", 48, 13}, {"ABOUT", 48, 15}, {"QUIT", 48, 17} };
	DrawListMenu(listMenu);

	int curChoice = 0;
	int nextChoice = 0;
	while (true) {
		if (_kbhit()) {
			char key = toupper(_getch());
			if (key == 'W') {
				nextChoice = curChoice == 0 ? 3 : curChoice - 1;
				HightlightList(listMenu, curChoice, nextChoice);
			}
			else if (key == 'S') {
				nextChoice = curChoice == 3 ? 0 : curChoice + 1;
				HightlightList(listMenu, curChoice, nextChoice);
			}
			else if (key == ENTER) // Enter 
				return curChoice;
		}
	}
	return -1;
}

// Vẽ menu
void DrawMenu() {

	DrawBorderMenu();
	DrawSnakeText();
}

// vẽ List file
void DrawListFile(vector <List> listFile, int curChoice, int start, int end) {

	if (!listFile.empty()) {
		SetTextColor(WHITE_COLOR);
		for (int i = start; i <= end; i++) {
			GotoXY(listFile[i].x, listFile[i].y);
			cout << listFile[i].name << "             ";
		}

		if (!listFile[curChoice].name.empty()) {
			SetTextColor(DARK_RED_COLOR);
			GotoXY(listFile[curChoice].x - 4, listFile[curChoice].y); cout << ">> " << listFile[curChoice].name << "             ";
		}
	}

	SetTextColor(WHITE_COLOR);
	GotoXY(42, 20); cout << "press Esc to go back";
}

// Vẽ load menu
void DrawBorderLoadMenu() {

	SetTextColor(WHITE_COLOR);
	GotoXY(30, 10); cout << TOP_LEFT_BORDER;
	GotoXY(75, 10); cout << TOP_RIGHT_BORDER;
	GotoXY(30, 18); cout << BOTTOM_LEFT_BORDER;
	GotoXY(75, 18); cout << BOTTOM_RIGHT_BORDER;

	for (int i = 31; i < 75; i++) {
		GotoXY(i, 10); cout << WIDTH_MENU_BORDER;
		GotoXY(i, 18); cout << WIDTH_MENU_BORDER;
	}

	for (int i = 11; i < 18; i++) {
		GotoXY(30, i); cout << HEIGHT_MENU_BORDER;
		GotoXY(75, i); cout << HEIGHT_MENU_BORDER;
	}
}

// Láy tên file cần load
string GetFileLoad() {
	
	ifstream fileInput(FILE_SAVE);
	vector <List> listFile;


	while (!fileInput.eof()) {
		string text;
		getline(fileInput, text);
		if (!text.empty())
			listFile.push_back({ text, 0, 0 });
	}

	Clrscr();
	DrawMenu();
	DrawBorderLoadMenu();

	if (!listFile.empty()) {
		listFile[0].x = 42;
		listFile[0].y = 12;
		for (int i = 1; i < 5 && i < listFile.size(); i++) {
			listFile[i].x = listFile[0].x;
			listFile[i].y = listFile[i - 1].y + 1;
		}
	}

	int curChoice = 0;
	int nextChoice = 0;
	int start = 0;
	int end = listFile.size() <= 4 ? listFile.size() - 1 : 4;

	DrawListFile(listFile, curChoice, start, end);

	while (true) {
		if (_kbhit()) {
			char key = toupper(_getch());
			if (key == 'W') {
				if (curChoice == start && curChoice > 0) {
					curChoice--;
					start--;
					end--;
					for (int i = start; i <= end; i++) {
						listFile[i].x = listFile[i + 1].x;
						listFile[i].y = listFile[i + 1].y;
					}

					DrawListFile(listFile, curChoice, start, end);
				}
				else if (curChoice != 0) {
					HightlightList(listFile, curChoice, curChoice - 1);
				}
			}
			else if (key == 'S') {
				if (curChoice == end && curChoice < listFile.size() - 1) {
					curChoice++;
					start++;
					end++;
					for (int i = end; i >= start; i--) {
						listFile[i].x = listFile[i - 1].x;
						listFile[i].y = listFile[i - 1].y;
					}
					DrawListFile(listFile, curChoice, start, end);
				}
				else if (curChoice != listFile.size() - 1) {
					HightlightList(listFile, curChoice, curChoice + 1);
				}
			}
			else if (key == ENTER) // Enter 
				return listFile[curChoice].name;
			else if (key == ESC)
				return "***RETURN_TO_MEUNU***";
		}
	}

	fileInput.close();
	return "";
}

// Giới thiệu nhóm
void ShowAbout() {

	Clrscr();
	DrawMenu();

	SetTextColor(GREEN_COLOR);
	GotoXY(43, 10); cout << "SNAKE GAME BY TEAM 7";

	SetTextColor(WHITE_COLOR);
	GotoXY(32, 13); cout << "Huynh Minh Hieu                  18120371";
	GotoXY(32, 14); cout << "Luu Truong Duong                 19120489";
	GotoXY(32, 15); cout << "Le Minh Hau                      19120502";
	GotoXY(32, 16); cout << "Bach Thien Khoi                  19120549";
	GotoXY(42, 20); cout << "press Esc to go back";

	while (true) {
		if (_kbhit()) {
			char key = _getch();
			if (key == ESC)
				break;
		}
	}
}

// Khởi động lựa chọn
void ActiveSelect(int choice) {

	string fileName = "";

	switch (choice) {
	case 0:
		StartGame(fileName);
		break;
	case 1:
		fileName = GetFileLoad();
		if (fileName == "***RETURN_TO_MEUNU***")
			break;
		StartGame(fileName);
		break;
	case 2:
		ShowAbout();
		break;
	case 3:
		exit(0);
	}
}