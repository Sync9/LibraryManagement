//--modify from tested module --tested
#include"Header.h"
READER* readReaderInfoFromFile(char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) {
		printf("Fail to open %s", path);
		exit(1);
	}
	else {
		READER* head = NULL;
		READER* head_ptr = (READER*)malloc(sizeof(READER));
		if (head_ptr == NULL) {
			printf("Fail to apply memory\n");
			exit(1);
		}
		head_ptr = head;
		int cnt = 0;
		int c = fgetc(fp);
		while (c != EOF) {
			fseek(fp, -1, SEEK_CUR);
			READER* newnode = (READER*)malloc(sizeof(READER));
			if (newnode == NULL) {
				printf("Fail to apply memory\n");
				exit(1);
			}
			newnode->NEXT = NULL;
			fread(newnode, sizeof(READER), 1, fp);
			if (cnt == 0) {
				head = newnode;
				head_ptr = head;
				cnt++;
			}
			else {
				head_ptr->NEXT = newnode;
				head_ptr = head_ptr->NEXT;
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