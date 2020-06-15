#pragma once
#include "console.h"
#include "snake.h"

#define WIDTH 800
#define HEIGHT 400
#define WIDTH_MENU 106
#define HEIGHT_MENU 22

#define TOP_LEFT_BORDER (char)201
#define TOP_RIGHT_BORDER (char)187
#define BOTTOM_LEFT_BORDER (char)200
#define BOTTOM_RIGHT_BORDER (char)188
#define WIDTH_MENU_BORDER (char)205
#define HEIGHT_MENU_BORDER (char)186
#define LEFT_RIGHT_BOTTOM_BORDER (char)203
#define LEFT_RIGHT_TOP_BORDER (char)202
#define TOP_BOTTOM_LEFT_BORDER (char)185
#define TOP_BOTTOM_RIGHT_BORDER (char)204
#define FILE_SAVE "save.txt"

struct List {
	string name; // Tên list;
	int x, y; // Toạ độ (x, y);
};

// Vẽ viền menu
void DrawBorderMenu();

// Vẽ chữ Snake
void DrawSnakeText();

// Vẽ list menu
void DrawListMenu(vector <List> listMenu);

// Highlight lựa chọn
void HightlightList(vector <List> listMenu, int& curChoice, int nextChoice);

// Chọn menu
int SelectMenu();

// Vẽ menu
void DrawMenu();

// Vẽ list file
void DrawListFile(vector <List> listFile, int curChoice, int start, int end); 

// Vẽ load menu
void DrawBorderLoadMenu();

// Láy tên file cần load
string GetFileLoad();

// Khởi động lựa chọn
void ActiveSelect(int choice);