//--tested
#include "Header.h"
void deleteReaderInfo(READER* head, READER* infonode) {
	READER* cur_ptr = (READER*)malloc(sizeof(READER));
	READER* pre_ptr = (READER*)malloc(sizeof(READER));
	pre_ptr = head;
	cur_ptr = head;
	if (cur_ptr == NULL) printf("There is no user in the system\n");
	else {
		while (cur_ptr != NULL && strcmp(cur_ptr->username, infonode->username) != 0) {
			pre_ptr = cur_ptr;
			cur_ptr = cur_ptr->NEXT;
		}
		if (cur_ptr == NULL&&strcmp(cur_ptr->username, infonode->username) != 0) printf("The user isn't exist in the system\n");
		else pre_ptr->NEXT = cur_ptr->NEXT;
	}
	cur_ptr = NULL;
	free(cur_ptr);
	pre_ptr = NULL;
	free(pre_ptr);
}