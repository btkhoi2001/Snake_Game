#pragma once
#include "console.h"
#include "menu.h"

#define SIZE_GATE 6
#define MAX_SIZE_SNAKE 32
#define MAXA_SIZE_FOOD 4
#define MAX_SPEED 4
#define WIDTH_GAME 69
#define HEIGHT_GAME 19
#define FOOD_ICON (char)254
#define GATE_ICON (char)219
#define GATE_CENTER 1

// Hướng Đi vào cổng
enum GateSide {TOP, LEFT, RIGHT, BOTTOM};

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

// Tạo food
void GenerateFood(Point snake[], Point& food, int snakeSize);

// Tạo cổng 
void GenerateGate(Point snake[], Point gate[], int snakeSize);

// Khởi tạo giá trị
void Init(Point snake[], Point& food, Point& direction, int& snakeSize, int& foodScore, int& level, int& speed);

// Xoá message box
void DeleteMessageBox();

// Vẽ message box
void DrawMessageBox();

// Vẽ cổng
void DrawGate(Point gate[], bool inGate);

// Xoá cổng
void DeleteGate(Point gate[]);

// Vẽ snake và food
void DrawSnakeAndFood(Point snake[], Point gate[], Point& food, int& snakeSize, int& speed, int& level, int& foodScore, bool& inGate);

// Xoá snake và food
void DeleteSnakeAndFood(Point snake[], Point food, int snakeSize);

// Hiệu ứng khi chết
void DeadEffect(Point snake[], Point gate[], Point food, int snakeSize, int speed, int level, int foodScore, bool inGate);

// Di chuyển snake
void MoveSnake(Point snake[], Point gate[], Point direction, int snakeSize, bool& inGate);

// Thay đổi hướng đi của snake, kiểm tra pause, save
void GetKey(Point & direction, bool& escape);

// Kiểm tra điều kiện chết
bool EndGame(Point snake[], Point gate[], Point food, int snakeSize, int speed, int level, int foodScore, bool& escape, bool inGate);
// Bắt đầu game
void StartGame();
