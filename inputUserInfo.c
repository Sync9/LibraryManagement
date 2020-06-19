//--modify from tested module 
#include "Header.h"
USER* inputUserInfo(USER* head, USER* infonode) {
	USER* newnode = (USER*)malloc(sizeof(USER));
	if (newnode == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	USER* cur_ptr = (USER*)malloc(sizeof(USER));	
	if (cur_ptr == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	USER* pre_ptr = (USER*)malloc(sizeof(USER));
	if (pre_ptr == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	strcpy(newnode->name, infonode->name);
	strcpy(newnode->passwd, infonode->passwd);
	newnode->UL = infonode->UL;
	newnode->NEXT = NULL;
	cur_ptr = head;
	pre_ptr = head;
	while (cur_ptr != NULL) {
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