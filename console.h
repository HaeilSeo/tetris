#pragma once
#include <Windows.h>

class Console {

public:
	Console();
	~Console();

	void initKey();
	void gotoxy(int x, int y); 

};