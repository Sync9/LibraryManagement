#include "Header.h"
void deleteUserInfo(USER* head, USER* infonode) {
	USER* cur_ptr = (USER*)malloc(sizeof(USER));
	USER* pre_ptr = (USER*)malloc(sizeof(USER));
	pre_ptr = head;
	cur_ptr = head;
	if (cur_ptr == NULL) { 
		printf("There is no user in the system\n"); 
	}
	else {
		while (cur_ptr != NULL && strcmp(cur_ptr->name , infonode->name)!=0) {
			pre_ptr = cur_ptr;
			cur_ptr = cur_ptr->NEXT;
		}
		if (cur_ptr == NULL) { 
			controlFormat();
			printf("The user isn't exist in the system\n");
		}
		else pre_ptr->NEXT = cur_ptr->NEXT;
	}
	cur_ptr = NULL;
	free(cur_ptr);
	pre_ptr = NULL;
	free(pre_ptr);
}