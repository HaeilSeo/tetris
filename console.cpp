#include "console.h"

Console::Console()
{

}

Console::~Console()
{

}



void Console::gotoxy(int x, int y) {
	COORD Pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Console::initKey() {

	
}

