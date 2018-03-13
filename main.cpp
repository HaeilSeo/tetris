#include<stdio.h>
#include<windows.h>
#include"graphic.h"

struct DDS_PIXELFORMAT{
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwFourCC;
	DWORD dwRGBBitCount;
	DWORD dwRBitMask;
	DWORD dwGBitMask;
	DWORD dwBBitMask;
	DWORD dwABitMask;
};

struct DDS_HEADER {	
					//(����� �� ������� �ۼ��������)
	DWORD dwSize;	//����ü ��ü�� ũ�� 
	DWORD dwFlags;	//����Ÿ ���� ���� �˻�
	DWORD dwHeight; //�̹��� ����
	DWORD dwWidth;	//�̹��� ����
	DWORD dwPitchOrLinearSize; //�̹��� ���� ũ��
	DWORD dwDepth;	//3���� �̹��� ���� ����
	DWORD dwMipMapCount;	//�Ӹ�	(�̹����� ����Ҷ� ������ ���� ���ϰ� ���ش�)
	DWORD dwReserved1[11];
	DDS_PIXELFORMAT ddspf;	//�ȼ� ���� - ���� ����/�ȼ��� ��Ʈ��....
	DWORD dwCaps;
	DWORD dwCaps2;
	DWORD dwCaps3;
	DWORD dwCaps4;
	DWORD dwReserved2;
};

struct DDS_FILE {
	DWORD magic;
	DDS_HEADER header;
	BYTE data[1];
};

int main() {
	FILE* fp = NULL;

	errno_t  errno;

	errno = fopen_s(&fp, "�Ͽ��ǿ����̴¼�.dds","rb");

	if (errno != 0) {
		fprintf(stderr, "���� ���� ���� :�����ڵ� %d\n", errno);
		return -1;
	}
	///////////////���� �б�//////////////////
	//(1) ���� ũ�� �˾� ����
	fseek(fp, 0, SEEK_END);	 //������ ��ġ�� �ǳ����� �̵���Ŵ
	int size = ftell(fp);	 //������ ũ�⸦ �о��
	fseek(fp, 0, SEEK_SET);	 //���� ��ġ�� ������ �̵� ��Ŵ

	//printf("������ ũ�� %d ����Ʈ\n", size);
	
	//(2)����ü�� ���� ũ�⸸ŭ �޸𸮸� �Ҵ�
	DDS_FILE* dds =(DDS_FILE*)new BYTE[size];	//�׳��� �ȵ��� ������
												//DDS_FILE*�� ���� ����ȯ ���� �����Ѵ�.

	//(3)�Ҵ���� �޸𸮿� ������ �о� ä��
	fread(dds, 1, size, fp);		//���Ͽ��� �о�� ��ü ũ��� 1*size

	///////////////���� �ݱ�//////////////////
	fclose(fp);
	
	////////////���Ͽ��� ���� ����Ÿ�� ����غ�/////////
	printf("���� �ڵ� : 0x%x\n", dds->magic);

	
	printf("�̹��� ���� : %d\n", dds->header.dwHeight);
	printf("�̹��� ���� : %d\n", dds->header.dwWidth);
	printf("�̹��� ����ũ�� : %d\n", dds->header.dwPitchOrLinearSize);

	///////////////�ȼ� ����///////////////
	printf("�̹��� �ȼ� �÷��� : 0x%x\n", dds->header.ddspf.dwFlags);
	printf("�̹��� �ȼ� ��Ʈ�� : %d\n", dds->header.ddspf.dwRGBBitCount);
	
	if (dds->header.ddspf.dwFlags == 0x41) {

		printf("�̹����� ������ �ʵǾ��� �̹����� (����)������ ����\n");
	}

	initGraphic();
	//////////////////���Ͽ��� ����Ÿ �о����/////////////////////
	while (true) {
		for (int y = 0; y < dds->header.dwHeight; y++) {

			for (int x = 0; x < dds->header.dwWidth; x++) {
				BYTE B = dds->data[y*dds->header.dwPitchOrLinearSize + x * 4 + 0];
				BYTE G = dds->data[y*dds->header.dwPitchOrLinearSize + x * 4 + 1];
				BYTE R = dds->data[y*dds->header.dwPitchOrLinearSize + x * 4 + 2];
				BYTE A = dds->data[y*dds->header.dwPitchOrLinearSize + x * 4 + 3];
				setPixel(x, y, R, G, B);
			}
		}
		render();
	}
	dds->data[0];
	return 0;
}