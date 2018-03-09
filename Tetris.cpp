#include "Tetris.h"


Tetris::Tetris()
{

}
Tetris::~Tetris()
{

}


void Tetris::TetrisMap(int x, int y) {
	for (int i = 1; i< y; i++) {
		for (int k = 1; k < x; k++) {
			_console.gotoxy(k, i);
			if (i == 1 || i == y-1) {
				printf("¢É");
			}
			else {
				if (k == 1 || k == x-1) {
					printf("¢É");
				}
			}
		}
	}
}

void Tetris::TetrisShape(int z, int x, int y) {


}
