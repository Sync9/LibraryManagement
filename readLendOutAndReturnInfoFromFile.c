#include"Header.h"
LOAR* readLendOutAndReturnInfoFromFile(char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		LOAR* head = NULL;
		LOAR* head_ptr = (LOAR*)malloc(sizeof(LOAR));
		if (head_ptr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		head_ptr = head;
		int cnt = 0;
		int c = fgetc(fp);
		while (c != EOF) {
			fseek(fp, -1, SEEK_CUR);
			LOAR* newnode = (LOAR*)malloc(sizeof(LOAR));
			if (newnode == NULL) {
				printf("Fail to apply memory\n");
				exit(1);
			}
			newnode->next = NULL;
			fread(newnode, sizeof(LOAR), 1, fp);
			if (cnt == 0) {
				head = newnode;
				head_ptr = head;
				cnt++;
			}
			else {
				head_ptr->next = newnode;
				head_ptr = head_ptr->next;
			}
			c = fgetc(fp);
		}
		head_ptr = NULL;
		free(head_ptr);
		if (c == EOF) fseek(fp, -1, SEEK_CUR);
		fclose(fp);
		return head;
	}
}