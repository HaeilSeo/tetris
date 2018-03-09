#include"main.h"


int main() {
	Tetris Tetris1;






	srand(time(0));

	int i=1;
	for (;;) {
		int r = rand() % 7;
		
		for (int t = 0; t < 4; t++) {
			for (int k = 0; k < 4; k++) {
				Tetris1.TetrisMap(15, 25);
				Tetris1._console.gotoxy(BlockShape[r][t][k].x+5, BlockShape[r][t][k].y+i);
				printf("бс");
			}
			i++;
			if (i == 21) {
				i = 1;
			}
			Sleep(50);
			system("cls");
		}
	}	

	system("pause");
	return 0;
}



