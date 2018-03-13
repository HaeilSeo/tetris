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
					//(멤버를 꼭 순서대로 작성해줘야함)
	DWORD dwSize;	//구조체 자체의 크기 
	DWORD dwFlags;	//데이타 압축 여부 검사
	DWORD dwHeight; //이미지 높이
	DWORD dwWidth;	//이미지 넓이
	DWORD dwPitchOrLinearSize; //이미지 한줄 크기
	DWORD dwDepth;	//3차원 이미지 깊이 정보
	DWORD dwMipMapCount;	//밉맵	(이미지를 축소할때 깨지는 것을 덜하게 해준다)
	DWORD dwReserved1[11];
	DDS_PIXELFORMAT ddspf;	//픽셀 형식 - 압축 여부/픽셀으 비트수....
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

	errno = fopen_s(&fp, "하울의움직이는성.dds","rb");

	if (errno != 0) {
		fprintf(stderr, "파일 열기 실패 :에러코드 %d\n", errno);
		return -1;
	}
	///////////////파일 읽기//////////////////
	//(1) 파일 크기 알아 오기
	fseek(fp, 0, SEEK_END);	 //파일의 위치를 맨끝으로 이동시킴
	int size = ftell(fp);	 //파일의 크기를 읽어옴
	fseek(fp, 0, SEEK_SET);	 //파일 위치를 앞으로 이동 시킴

	//printf("파일의 크기 %d 바이트\n", size);
	
	//(2)구조체에 파일 크기만큼 메모리를 할당
	DDS_FILE* dds =(DDS_FILE*)new BYTE[size];	//그냥은 안들어가기 때문에
												//DDS_FILE*로 강제 형변환 시켜 저장한다.

	//(3)할당받은 메모리에 파일을 읽어 채움
	fread(dds, 1, size, fp);		//파일에서 읽어올 전체 크기는 1*size

	///////////////파일 닫기//////////////////
	fclose(fp);
	
	////////////파일에서 읽은 데이타를 출력해봄/////////
	printf("매직 코드 : 0x%x\n", dds->magic);

	
	printf("이미지 넓이 : %d\n", dds->header.dwHeight);
	printf("이미지 높이 : %d\n", dds->header.dwWidth);
	printf("이미지 한줄크기 : %d\n", dds->header.dwPitchOrLinearSize);

	///////////////픽셀 정보///////////////
	printf("이미지 픽셀 플래그 : 0x%x\n", dds->header.ddspf.dwFlags);
	printf("이미지 픽셀 비트수 : %d\n", dds->header.ddspf.dwRGBBitCount);
	
	if (dds->header.ddspf.dwFlags == 0x41) {

		printf("이미지가 압축이 않되었고 이미지도 (알파)투명도가 있음\n");
	}

	initGraphic();
	//////////////////파일에서 데이타 읽어오기/////////////////////
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