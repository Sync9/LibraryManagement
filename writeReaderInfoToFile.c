//--modify from tested module --tested
#include"Header.h"
void writeReaderInfotoFile(char* path, READER* head) {
	FILE* fp = fopen(path, "wb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		READER* cur_ptr = (READER*)malloc(sizeof(READER));
		if (cur_ptr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		else {
			cur_ptr = head;
			while (cur_ptr != NULL) {
				fwrite(cur_ptr, sizeof(READER), 1, fp);
				cur_ptr = cur_ptr->NEXT;
			}
			free(cur_ptr);
		}
	}
	fclose(fp);
}