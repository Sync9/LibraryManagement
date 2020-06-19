//---tested
#include "Header.h"
READER* inputReaderInfo(READER* head, READER* infonode) {
	READER* newnode = (READER*)malloc(sizeof(READER));
	if (newnode == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	READER* cur_ptr = (READER*)malloc(sizeof(READER));
	if (cur_ptr == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	READER* pre_ptr = (READER*)malloc(sizeof(READER));
	if (pre_ptr == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	strcpy(newnode->username, infonode->username);
	strcpy(newnode->readername, infonode->readername);
	strcpy(newnode->workplace, infonode->workplace);
	strcpy(newnode->phonenumber, infonode->phonenumber);
	newnode->availablebook = infonode->availablebook;
	newnode->unavailablebook = infonode->unavailablebook;
	newnode->NEXT = NULL;
	cur_ptr = head;
	pre_ptr = head;
	while (cur_ptr != NULL&&strcmp(cur_ptr->readername,infonode->readername)<=0) {
		pre_ptr = cur_ptr;
		cur_ptr = cur_ptr->NEXT;
	}
	if (pre_ptr == cur_ptr) head = newnode;
	else pre_ptr->NEXT = newnode;
	newnode->NEXT = cur_ptr;
	pre_ptr = NULL;
	cur_ptr = NULL;
	free(cur_ptr);
	free(pre_ptr);
	return head;
}