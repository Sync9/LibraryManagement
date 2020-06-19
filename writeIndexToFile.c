//--modify from tested module
#include "Header.h"
void writeIndexToFile(char* path, INDEX* arr, int* arrlen) {
	FILE* fp = fopen(path, "wb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		if (arr != NULL) {
			fwrite(arr, sizeof(INDEX), *arrlen, fp);
		}
		fclose(fp);
	}
}