#include"Header.h"
void writeLendOutAndReturnInfotoFile(char* path, LOAR* head) {
	FILE* fp = fopen(path, "wb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		LOAR* cur_ptr = (LOAR*)malloc(sizeof(LOAR));
		if (cur_ptr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		else {
			cur_ptr = head;
			while (cur_ptr != NULL) {
				fwrite(cur_ptr, sizeof(LOAR), 1, fp);
				cur_ptr = cur_ptr->next;
			}
			free(cur_ptr);
		}
	}
	fclose(fp);
}