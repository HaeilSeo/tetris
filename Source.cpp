#include "Block.h"

using namespace std;

void gotoxy(int x, int y) {
	COORD Pos{ x*2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
enum BlockShape{I=1,J,L,O,S,T,Z};
//
//int main() {
//	int ctr;
//
//	while (1) {
//		scanf_s("%d", &ctr);
//		system("cls");
//		switch (ctr) {
//		case 1: gotoxy(ctr, 1);
//				printf("бс");
//				gotoxy(ctr+1, 1);
//				printf("бс");
//				gotoxy(ctr+2, 1);
//				printf("бс");
//				gotoxy(ctr+3, 1);
//				printf("бс");
//				break;
//		case 2: 
//			gotoxy(1, 1);
//			printf("бс");
//			gotoxy(1, 2);
//			printf("бс");
//			gotoxy(2, 2);
//			printf("бс");
//			gotoxy(3, 2);
//			printf("бс");
//			break;
//		}
//		/*case 3:
//			gotoxy(1, 1);
//			printf("бс");
//			gotoxy(2, 1);
//			printf("бс");
//			gotoxy(3, 1);
//			printf("бс"); 
//			gotoxy(1, 1);
//			printf("бс");
//			break;*/
//	}
//}


int main(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				gotoxy(_blockShape[i][j][k]._blockX+10, _blockShape[i][j][k]._blockY+10);
				printf("бс");
			}
			Sleep(1000);
			system("cls");
		}

	}



}