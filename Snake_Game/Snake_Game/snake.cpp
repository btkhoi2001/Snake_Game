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
	GotoXY(78, 18); cout << "SAVE:               L";
	GotoXY(78, 19); cout << "BACK TO MENU:       ESC";
}

// Câp nhật điểm số
void Update(int foodScore, int level) {

	SetTextColor(WHITE_COLOR);
	GotoXY(92, 6); cout << foodScore;
	GotoXY(92, 8); cout << level;
}

// Kiểm tra food có trùng với thân snake
bool IsValid(Point snake[], int snakeSize, int x, int y) {

	for (int i = 0; i < snakeSize; i++)
		if (snake[i].x == x && snake[i].y == y)
			return false;

	return true;
}

// Tạo food
void GenerateFood(Point snake[], Point& food, int snakeSize) {

	int x, y;
	srand(time(0));

	do {
		x = 1 + rand() % (WIDTH_GAME + 1);
		y = 1 + rand() % (HEIGHT_GAME + 1);
	} while (!IsValid(snake, snakeSize, x, y));

	food.x = x;
	food.y = y;
}

// Tạo cổng
void GenerateGate(Point snake[], Point gate[], int snakeSize) {

	while (true) {
		srand(time(0));
		int x = 3 + rand() % (WIDTH_GAME - 3);
		int y = 3 + rand() % (HEIGHT_GAME - 3);
		int side = rand() % 4;

		switch (side) {
		case TOP:
			for (int i = 0; i < 3; i++) {
				if (IsValid(snake, snakeSize, x, y) && IsValid(snake, snakeSize, x, y + 1)) {
					gate[i].x = x;
					gate[i].y = y;
					gate[i + 3].x = x++;
					gate[i + 3].y = y + 1;
					if (i == 2) {
						gate[GATE_CENTER].x0 = gate[GATE_CENTER].x;
						gate[GATE_CENTER].y0 = gate[GATE_CENTER].y + 1;
						return;
					}
				}
				else break;
			}
			break;;
		case BOTTOM:
			for (int i = 0; i < 3; i++) {
				if (IsValid(snake, snakeSize, x, y) && IsValid(snake, snakeSize, x, y + 1)) {
					gate[i].x = x;
					gate[i].y = y + 1;
					gate[i + 3].x = x++;
					gate[i + 3].y = y;
					if (i == 2) {
						gate[GATE_CENTER].x0 = gate[GATE_CENTER].x;
						gate[GATE_CENTER].y0 = gate[GATE_CENTER].y - 1;
						return;
					}
				}
				else break;
			}
			break;;
		case LEFT:
			for (int i = 0; i < 3; i++) {
				if (IsValid(snake, snakeSize, x, y) && IsValid(snake, snakeSize, x + 1, y)) {
					gate[i].x = x;
					gate[i].y = y;
					gate[i + 3].x = x + 1;
					gate[i + 3].y = y++;
					if (i == 2) {
						gate[GATE_CENTER].x0 = gate[GATE_CENTER].x + 1;
						gate[GATE_CENTER].y0 = gate[GATE_CENTER].y;
						return;
					}
				}
				else break;
			}
			break;
		case RIGHT:
			for (int i = 0; i < 3; i++) {
				if (IsValid(snake, snakeSize, x, y) && IsValid(snake, snakeSize, x + 1, y)) {
					gate[i].x = x + 1;
					gate[i].y = y;
					gate[i + 3].x = x;
					gate[i + 3].y = y++;
					if (i == 2) {
						gate[GATE_CENTER].x0 = gate[GATE_CENTER].x - 1;
						gate[GATE_CENTER].y0 = gate[GATE_CENTER].y;
						return;
					}
				}
				else break;
			}
			break;
		}
	}
}

// Khởi tạo giá trị
void Init(Point snake[], Point& food, Point& direction, int& snakeSize, int& foodScore, int& level, int& speed) {

	snakeSize = 6;
	foodScore = 0;
	level = 1;
	direction.x = 0;
	direction.y = 0;
	speed = 120;

	char snakeName[] = "18120371191204891912050219120549";
	for (int i = 0; i < MAX_SIZE_SNAKE; i++)
		snake[i].chr = snakeName[i];

	for (int i = 0; i < snakeSize; i++) {
		snake[i].x = 10 - i;
		snake[i].y = 4;
		snake[i].x0 = snake[i].x;
		snake[i].y0 = snake[i].y;
	}

	GenerateFood(snake, food, snakeSize);
}

// Xoá message box 
void DeleteMessageBox() {

	for (int i = 20; i < 53; i++)
		for (int j = 7; j < 14; j++) {
			GotoXY(i, j);
			cout << " ";
		}
}

// Vẽ messagae box
void DrawMessageBox() {

	SetTextColor(WHITE_COLOR);
	GotoXY(20, 7); cout << TOP_LEFT_BORDER;
	GotoXY(52, 7); cout << TOP_RIGHT_BORDER;
	GotoXY(20, 13); cout << BOTTOM_LEFT_BORDER;
	GotoXY(52, 13); cout << BOTTOM_RIGHT_BORDER;

	for (int i = 21; i < 52; i++) {
		GotoXY(i, 7); cout << WIDTH_MENU_BORDER;
		GotoXY(i, 13); cout << WIDTH_MENU_BORDER;
	}

	for (int i = 8; i < 13; i++) {
		GotoXY(20, i); cout << HEIGHT_MENU_BORDER;
		GotoXY(52, i); cout << HEIGHT_MENU_BORDER;
	}
}

// Vẽ cổng
void DrawGate(Point gate[], bool inGate) {

	for (int i = 0; i < SIZE_GATE; i++) {
		if (inGate) {
			if (i != GATE_CENTER + 3) {
				GotoXY(gate[i].x, gate[i].y);
				cout << GATE_ICON;
			}
		}
		else if (i != GATE_CENTER) {
			GotoXY(gate[i].x, gate[i].y);
			cout << GATE_ICON;
		}
	}

}

// Xoá cổng
void DeleteGate(Point gate[]) {

	for (int i = 0; i < SIZE_GATE; i++) {
		GotoXY(gate[i].x, gate[i].y); cout << " ";
		gate[i].x = -1;
		gate[i].y = -1;
		gate[i].x0 = -1;
		gate[i].y0 = -1;
	}
}

// Vẽ snake và food;
void DrawSnakeAndFood(Point snake[], Point gate[], Point& food, int& snakeSize, int& speed, int& level, int& foodScore, bool& inGate) {

	if (inGate && (snake[snakeSize - 1].x != gate[GATE_CENTER].x0 || snake[snakeSize - 1].y != gate[GATE_CENTER].y0)) {
		inGate = false;
		level++;
		speed -= 15;
		GenerateFood(snake, food, snakeSize);
		DeleteGate(gate);
	}

	SetTextColor(WHITE_COLOR);
	for (int i = 1; i < snakeSize; i++) {
		GotoXY(snake[i].x, snake[i].y); 
		cout << snake[i].chr;
	}

	SetTextColor(DARK_BLUE_COLOR);
	GotoXY(snake[0].x, snake[0].y); cout << snake[0].chr;

	SetTextColor(WHITE_COLOR);
	if (snake[snakeSize - 1].x0 != snake[snakeSize - 1].x || snake[snakeSize - 1].y0 != snake[snakeSize - 1].y) {
		GotoXY(snake[snakeSize - 1].x0, snake[snakeSize - 1].y0);
		cout << " ";
	}

	if (snake[0].x == food.x && snake[0].y == food.y) {
		foodScore++;
		snake[snakeSize].x = snake[snakeSize - 1].x0;
		snake[snakeSize].y = snake[snakeSize - 1].y0;
		snakeSize++;
		if (foodScore % 4 != 0)
			GenerateFood(snake, food, snakeSize);
		else {
			GenerateGate(snake, gate, snakeSize);
			food.x = -1;
			food.y = -1;
		}
		
	}

	if (food.x != -1 && food.y != -1) {
		SetTextColor(RED_COLOR);
		GotoXY(food.x, food.y); cout << FOOD_ICON;
	}
	else {
		DrawGate(gate, inGate);
	}
}

// Xoá snake và food
void DeleteSnakeAndFood(Point snake[], Point food, int snakeSize) {

	for (int i = 0; i < snakeSize; i++) {
		GotoXY(snake[i].x, snake[i].y);
		cout << " ";
	}

	GotoXY(food.x, food.y); cout << " ";
}

// Hiệu ứng khi chết
void DeadEffect(Point snake[], Point gate[], Point food,  int snakeSize, int speed, int level, int foodScore, bool inGate) {

	for (int i = 0; i < 4; i++) {
		DeleteSnakeAndFood(snake, food, snakeSize);
		Sleep(300);
		DrawSnakeAndFood(snake, gate, food, snakeSize, speed, level, foodScore, inGate);
		Sleep(300);
	}
}

// Di chuyển snake
void MoveSnake(Point snake[], Point gate[], Point direction, int snakeSize, bool& inGate) {

	if (direction.x != 0 || direction.y != 0) { 
		if (snake[0].x == gate[GATE_CENTER].x0 && snake[0].y == gate[GATE_CENTER].y0) {
			snake[0].x0 = gate[GATE_CENTER].x0;
			snake[0].y0 = gate[GATE_CENTER].y0;
		}
		else {
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].x += direction.x;
			snake[0].y += direction.y;
		}

		if (snake[snakeSize - 1].x == gate[GATE_CENTER].x0 && snake[snakeSize - 1].y == gate[GATE_CENTER].y0)
			inGate = true;

		if (inGate && snake[snakeSize - 1].x == gate[GATE_CENTER].x0 && snake[snakeSize - 1].y == gate[GATE_CENTER].y0 && snake[0].x == gate[GATE_CENTER].x0 && snake[0].y == gate[GATE_CENTER].y0) {
			snake[0].x += direction.x;
			snake[0].y += direction.y;
		}

		for (int i = 1; i < snakeSize; i++) {
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
}

// Thay đổi hướng đi của snake, kiểm tra pause, save
void GetKey(Point& direction, bool& escape) {

	if (_kbhit()) {
		char key = toupper(_getch());

		if (key == 'W') {
			if (direction.y != 1) {
				direction.x = 0;
				direction.y = -1;
			}
		}
		else if (key == 'S') {
			if (direction.y != -1) {
				direction.x = 0;
				direction.y = 1;
			}
		}
		else if (key == 'A') {
			if (direction.x == 0 && direction.y == 0) {
				direction.x = 1;
				direction.y = 0;
			}
			else if (direction.x != 1) {
				direction.x = -1;
				direction.y = 0;
			}
		}
		else if (key == 'D') {
			if (direction.x != -1) {
				direction.x = 1;
				direction.y = 0;
			}
		}
		else if (key == 'P') {
			DeleteMessageBox();
			DrawMessageBox();
			GotoXY(34, 9); cout << "PAUSE";
			GotoXY(24, 11); cout << "Press any key to continue";
			while (true) {
				if (_kbhit()) {
					_getch();
					DeleteMessageBox();
					DrawGame();
					break;
				}
			}
		}
		else if (key == (char)27) { // ESC
			escape = true;
		}
	}
}

// Kiểm tra điều kiện chết
bool EndGame(Point snake[], Point gate[], Point food, int snakeSize, int speed, int level, int foodScore, bool& escape, bool inGate) {

	if (escape) {
		DeleteMessageBox();
		DrawMessageBox();
		GotoXY(31, 9); cout << "BACK TO MENU";
		GotoXY(27, 11); cout << "Yes (Y)       No (N)";
		while (true) {
			if (_kbhit()) {
				char key = toupper(_getch());
				if (key == 'Y') {
					DeleteMessageBox();
					escape = true;
					break;
				}
				else if (key == 'N') {
					DeleteMessageBox();
					DrawGame();
					escape = false;
					break;
				}
			}
		}
		return escape;
	}

	for (int i = 1; i < snakeSize; i++) {
		if (snake[0].x != gate[GATE_CENTER].x0 && snake[0].y != gate[GATE_CENTER].y0 && snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
			DeadEffect(snake, gate, food, snakeSize, speed, level, foodScore, inGate);
			return true;
		}
	}

	for (int i = 0; i < WIDTH_GAME + 3; i++) {
		if (snake[0].x == i && (snake[0].y == 0 || snake[0].y == HEIGHT_GAME + 2)) {
			DeadEffect(snake, gate, food, snakeSize, speed, level, foodScore, inGate);
			return true;
		}
	}

	for (int i = 0; i < HEIGHT_GAME + 3; i++) {
		if ((snake[0].x == 0 || snake[0].x == WIDTH_GAME + 2) && snake[0].y == i) {
			DeadEffect(snake, gate, food, snakeSize, speed, level, foodScore, inGate);
			return true;
		}
	}

	for (int i = 0; i < SIZE_GATE; i++) {
		if ((i != GATE_CENTER && i != GATE_CENTER + 3 && snake[0].x == gate[i].x && snake[0].y == gate[i].y) || (snake[0].x == gate[GATE_CENTER].x0 && snake[0].y == gate[GATE_CENTER].y0 && snake[0].x0 != gate[GATE_CENTER].x && snake[0].y0 != gate[GATE_CENTER].y)) {
			DeadEffect(snake, gate, food, snakeSize, speed, level, foodScore, inGate);
			return true;
		}
	}

	return false;
}

// Bắt đầu game
void StartGame(string fileName) {

	Clrscr();
	DrawGame();

	Point snake[MAX_SIZE_SNAKE], gate[SIZE_GATE];
	Point food, direction;
	int snakeSize, level, foodScore, speed;
	bool escape = false, inGate = false;

	Init(snake, food, direction, snakeSize, foodScore, level, speed);

	while (!EndGame(snake, gate, food, snakeSize, speed, level, foodScore, escape, inGate)) {
		MoveSnake(snake, gate, direction, snakeSize, inGate);
		GetKey(direction, escape);
		DrawSnakeAndFood(snake, gate, food, snakeSize, speed, level, foodScore, inGate);
		Update(foodScore, level);
		Sleep(speed);
	}

}
