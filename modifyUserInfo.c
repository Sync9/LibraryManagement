//--modify from tested module
#include "Header.h"
void modifyUserInfo(USER* head, USER* infonode) {
	USER* cur_ptr = (USER*)malloc(sizeof(USER));
	cur_ptr = head;
	if (cur_ptr == NULL) printf("There is no user in the system\n");
	else {
		while (cur_ptr != NULL&&strcmp(cur_ptr->name,infonode->name)!=0) cur_ptr = cur_ptr->NEXT;
		if (cur_ptr == NULL) printf("The user isn't exist in the system\n");
		else {
			strcpy(cur_ptr->passwd, infonode->passwd);
			cur_ptr->UL = infonode->UL;
		}
	}
	cur_ptr = NULL;
	free(cur_ptr);
}