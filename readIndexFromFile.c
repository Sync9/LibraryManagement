//modify from tested moudle
#include "Header.h"
INDEX* readIndexFromFile(int* arrlen, char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		*arrlen = getBlockNumber(fp, sizeof(INDEX));
		if (*arrlen == 0) return NULL;
		INDEX* arr = (INDEX*)malloc(sizeof(INDEX) * *arrlen);
		if (arr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		fread(arr, sizeof(INDEX), *arrlen, fp);
		fclose(fp);
		return arr;
	}
}