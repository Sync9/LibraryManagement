#include"Header.h"
MBI* readMainBookIndexFromFile(int* arrlen, char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		*arrlen = getBlockNumber(fp, sizeof(MBI));
		if (*arrlen == 0) return NULL;
		MBI* arr = (MBI*)malloc(sizeof(MBI) * *arrlen);
		if (arr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		fread(arr, sizeof(MBI), *arrlen, fp);
		fclose(fp);
		return arr;
	}
}