#pragma once
#include "console.h"
#include "menu.h"

#define MAX_SIZE_SNAKE 40
#define MAXA_SIZE_FOOD 4
#define MAX_SPEED 4

// Đốt rắn
struct Point {
	// Toạ độ đốt rắn hiện tại
	int x, y;
	// Toạ độ đốt rắn trước đó
	int x0, y0;
};

// Vẽ giao diện game
void DrawGame();

// Khởi tạo giá trị
void Init();

// Bắt đầu game
void StartGame();
