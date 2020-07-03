//--tested
#include "Header.h"
READER* deleteReaderInfo(READER* head, READER* infonode) {
	READER* cur_ptr = (READER*)malloc(sizeof(READER));
	READER* pre_ptr = (READER*)malloc(sizeof(READER));
	pre_ptr = head;
	cur_ptr = head;
	if (cur_ptr == NULL) printf("There is no reader in the system\n");
	else {
		while (cur_ptr != NULL && strcmp(cur_ptr->username, infonode->username) != 0) {
			pre_ptr = cur_ptr;
			cur_ptr = cur_ptr->NEXT;
		}
		if (cur_ptr == NULL) {
			printf("The user isn't exist in the system\n");
		}
		else if(cur_ptr==head) {
			pre_ptr=head;
			head=head->NEXT;
			free(pre_ptr);
		}
		else pre_ptr->NEXT = cur_ptr->NEXT;
	}
	return head;
	cur_ptr = NULL;
	free(cur_ptr);
	pre_ptr = NULL;
	free(pre_ptr);
}
