#include"Header.h"
void creatFile(char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) fp = fopen(path, "wb");
	fclose(fp);
}