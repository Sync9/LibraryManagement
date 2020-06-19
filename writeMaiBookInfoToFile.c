//--tested
#include"Header.h"
void writeMainBookInfoToFile(char* path, BOOK* arr, int* arrlen) {
	FILE* fp = fopen(path, "wb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		if (arr != NULL) {
			fwrite(arr, sizeof(BOOK), *arrlen, fp);
			fclose(fp);
		}
	}
}