#pragma once
#include <stdio.h>
#include "console.h"

class Tetris {
public:
	Tetris();
	~Tetris();

public:
	void TetrisMap(int x, int y);
	void TetrisShape(int z, int x, int y);

public:
	Console _console;


};


