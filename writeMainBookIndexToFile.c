#include"Header.h"
void writeMainBookIndexToFile(char* path, MBI* arr, int* arrlen) {
		FILE* fp = fopen(path, "wb");
		if (fp == NULL) {
			printf("Fail to open %s", path);
			exit(1);
		}
		else {
			if (arr != NULL) {
				fwrite(arr, sizeof(MBI), *arrlen, fp);
				fclose(fp);
			}
		}
}