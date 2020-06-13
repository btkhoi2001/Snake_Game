#include "snake.h"

// Vẽ giao diện game
void DrawGame() {

	DrawBorderMenu();

	for (int i = 1; i < HEIGHT_MENU - 1; i++) {
		GotoXY(71, i);
		cout << HEIGHT_MENU_BORDER;
	}

	for (int i = 72; i < WIDTH_MENU - 1; i++) {
		GotoXY(i, 4); cout << WIDTH_MENU_BORDER;
		GotoXY(i, 10); cout << WIDTH_MENU_BORDER;
	}

	GotoXY(71, 0); cout << LEFT_RIGHT_BOTTOM_BORDER;
	GotoXY(71, HEIGHT_MENU - 1); cout << LEFT_RIGHT_TOP_BORDER;
	GotoXY(71, 4); cout << TOP_BOTTOM_RIGHT_BORDER;
	GotoXY(71, 10); cout << TOP_BOTTOM_RIGHT_BORDER;
	GotoXY(WIDTH_MENU - 1, 4); cout << TOP_BOTTOM_LEFT_BORDER;
	GotoXY(WIDTH_MENU - 1, 10); cout << TOP_BOTTOM_LEFT_BORDER;
	SetTextColor(GREEN_COLOR);
	GotoXY(84, 2); cout << "SNAKE GAME";
	SetTextColor(WHITE_COLOR);
	GotoXY(80, 6); cout << "SCORE:";
	GotoXY(80, 8); cout << "LEVEL:";
	GotoXY(78, 12); cout << "MOVE UP:            W";
	GotoXY(78, 13); cout << "MOVE DOWN:          S";
	GotoXY(78, 14); cout << "MOVE LEFT:          A";
	GotoXY(78, 15); cout << "MOVE RIGHT:         D";
	GotoXY(78, 17); cout << "PAUSE:              P";
	GotoXY(78, 18); cout << "SAVE:               O";
	GotoXY(78, 19); cout << "BACK TO MENU:       ESC";
}

// Khởi tạo giá trị
void Init() {

}

// Bắt đầu game
void StartGame() {

	Clrscr();
	DrawGame();
}
