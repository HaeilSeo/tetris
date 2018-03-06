#include<cstdio>
#include<cstdlib>
#include<windows.h>

void gotoxy(int x, int y) {
	COORD Pos{ x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
enum BlockShape { I = 1, J, L, O, S, T, Z };

struct Point 
{ 
	int block_X, block_Y; 
};
