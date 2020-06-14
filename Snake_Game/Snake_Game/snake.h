#pragma once
#include "console.h"
#include "menu.h"

#define MAX_SIZE_SNAKE 32
#define MAXA_SIZE_FOOD 4
#define MAX_SPEED 4
#define WIDTH_GAME 69
#define HEIGHT_GAME 19
#define FOOD_ICON (char)254

#define SPEED_1 150
#define SPEED_2
#define SPEED_3
#define SPEED_4

// Đốt rắn
struct Point {
	// Kí tự trong MSSV
	char chr;
	// Toạ độ đốt rắn hiện tại
	int x, y;
	// Toạ độ đốt rắn trước đó
	int x0, y0;
};

// Vẽ giao diện game
void DrawGame();

// Câp nhật điểm số
void Update(int foodScore, int level);

// Kiểm tra food có trùng với thân snake
bool IsValid(Point snake[], int snakeSize, int x, int y);

// Tạo toạ độ food
void GenerateFood(Point snake[], Point& food, int snakeSize);

// Khởi tạo giá trị
void Init(Point snake[], Point& food, Point& direction, int& snakeSize, int& foodScore, int& level, int& speed);

// Vẽ snake và food
void DrawSnakeAndFood(Point snake[], Point& food, int& snakeSize, int& foodScore);

// Xoá snake và food
void DeleteSnakeAndFood(Point snake[], Point food, int snakeSize);

// Hiệu ứng khi chết
void DeadEffect(Point snake[], Point food, int snakeSize, int foodScore);

// Di chuyển snake
void MoveSnake(Point snake[], Point direction, int snakeSize);

// Thay đổi hướng đi của snake
void ChangeDirection(Point& direction);

// Kiểm tra điều kiện chết
bool EndGame(Point snake[], Point food, int snakeSize, int foodScore);

// Bắt đầu game
void StartGame();
