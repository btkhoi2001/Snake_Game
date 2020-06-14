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

// Tạo toạ độ food
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

// Khởi tạo giá trị
void Init(Point snake[], Point& food, Point& direction, int& snakeSize, int& foodScore, int& level, int& speed) {

	snakeSize = 6;
	foodScore = 0;
	level = 1;
	direction.x = 0;
	direction.y = 0;
	speed = SPEED_1;

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

// Vẽ snake và food;
void DrawSnakeAndFood(Point snake[], Point& food, int& snakeSize, int& foodScore) {

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
		GenerateFood(snake, food, snakeSize);
		
	}

	SetTextColor(RED_COLOR);
	GotoXY(food.x, food.y); cout << FOOD_ICON;
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
void DeadEffect(Point snake[], Point food, int snakeSize, int foodScore) {

	for (int i = 0; i < 4; i++) {
		DeleteSnakeAndFood(snake, food, snakeSize);
		Sleep(300);
		DrawSnakeAndFood(snake, food, snakeSize, foodScore);
		Sleep(300);
	}
}

// Di chuyển snake
void MoveSnake(Point snake[], Point direction, int snakeSize) {

	if (direction.x != 0 || direction.y != 0) {
		snake[0].x0 = snake[0].x;
		snake[0].y0 = snake[0].y;
		snake[0].x += direction.x;
		snake[0].y += direction.y;

		for (int i = 1; i < snakeSize; i++) {
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
}

// Thay đổi hướng đi của snake
void ChangeDirection(Point& direction) {

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
			if (direction.x != 1) {
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
	}
}

// Kiểm tra điều kiện chết
bool EndGame(Point snake[], Point food, int snakeSize, int foodScore) {

	for (int i = 1; i < snakeSize; i++) {
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
			DeadEffect(snake, food, snakeSize, foodScore);
			return true;
		}
	}

	for (int i = 0; i < WIDTH_GAME + 3; i++) {
		if (snake[0].x == i && (snake[0].y == 0 || snake[0].y == HEIGHT_GAME + 2)) {
			DeadEffect(snake, food, snakeSize, foodScore);
			return true;
		}
	}

	for (int i = 0; i < HEIGHT_GAME + 3; i++) {
		if ((snake[0].x == 0 || snake[0].x == WIDTH_GAME + 2) && snake[0].y == i) {
			DeadEffect(snake, food, snakeSize, foodScore);
			return true;
		}
	}

	return false;
}

// Bắt đầu game
void StartGame() {

	Clrscr();
	DrawGame();

	Point snake[MAX_SIZE_SNAKE];
	Point food, direction;
	int snakeSize;
	int level;
	int foodScore;
	int speed;
	bool endGame = false;

	Init(snake, food, direction, snakeSize, foodScore, level, speed);

	while (!EndGame(snake, food, snakeSize, foodScore)) {
		MoveSnake(snake, direction, snakeSize);
		ChangeDirection(direction);
		DrawSnakeAndFood(snake, food, snakeSize, foodScore);

		Update(foodScore, level);

		Sleep(speed);
	}

	while(true) {

	}
}
