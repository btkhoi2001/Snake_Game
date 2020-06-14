#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

#define BLACK_COLOR 0
#define DARK_BLUE_COLOR 1
#define DARK_GREEN_COLOR 2
#define DARK_CYAN_COLOR 3
#define DARK_RED_COLOR 4
#define DARK_PINK_COLOR 5
#define DARK_YELLOW_COLOR 6
#define DARK_WHITE_COLOR 7
#define GREY_COLOR 8
#define BLUE_COLOR 9
#define GREEN_COLOR 10
#define CYAN_COLOR 11
#define RED_COLOR 12
#define PINK_COLOR 13
#define YELLOW_COLOR 14
#define WHITE_COLOR 15

// Cố định màn hình
void FixConsoleWindow();

// Thay đổi kích thước console
void ResizeConsole(int width, int height);

// Xoá thanh cuộn dọc
void NoVerticalScrollbar();

// Xoá con trỏ nháy
void NoCursorType();

// Xoá màn hình
void Clrscr();

// Di chuyển con trỏ console đến vị trí có toạ độ (x, y)
void GotoXY(int x, int y);

// Đổi màu chữ
void SetTextColor(int color);

