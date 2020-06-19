//--tested
#include"Header.h"
BOOK* readMainBookInfoFromFile(int* arrlen, char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		*arrlen = getBlockNumber(fp, sizeof(BOOK));
		if (*arrlen == 0) return NULL;
		BOOK* arr = (BOOK*)malloc(sizeof(BOOK) * *arrlen);
		if (arr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		fread(arr, sizeof(BOOK), *arrlen, fp);
		fclose(fp);
		return arr;
	}
}