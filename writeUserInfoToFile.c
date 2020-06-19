//--Tested
#include"Header.h"
void writeUserInfotoFile(char* path, USER* head) {
	FILE* fp = fopen(path, "wb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		USER* cur_ptr = (USER*)malloc(sizeof(USER));
		if (cur_ptr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		else {
			cur_ptr = head;
			while (cur_ptr != NULL) {
				fwrite(cur_ptr, sizeof(USER), 1, fp);
				cur_ptr = cur_ptr->NEXT;
			}
			free(cur_ptr);
		}
	}
	fclose(fp);
}