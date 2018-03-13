#pragma once
#include <Windows.h>

#define STARTX 0    //그래픽 화면의 시작
#define STARTY 0    //그래픽 화면의 시작
#define WIDTH  936    //그래픽 화면의 가로 크기
#define HEIGHT 234    //그래픽 화면의 세로 크기
#define GRAPHIC_MODE_0

void initGraphic();           
void clear(int r,  int g,  int b);  
void render();                 
void setPixel(int x, int y, int r, int g, int b);
void drawLine(int x0, int y0, int x1, int y1, int r, int g, int b);
void drawCircle(int cx, int cy, int radius, int r, int g, int b);
void drawRect(int x0, int y0, int x1, int y1, int r, int g, int b);