//--tested
#include "Header.h"
void modifyReaderInfo(READER* head, READER* infonode) {
	READER* cur_ptr = (READER*)malloc(sizeof(READER));
	cur_ptr = head;
	if (cur_ptr == NULL) printf("There is no user in the system\n");
	else {
		while (cur_ptr != NULL&& strcmp(infonode->username,cur_ptr->username)!=0) cur_ptr = cur_ptr->NEXT;
		if (cur_ptr == NULL) printf("The user isn't exist in the system\n");
		else {
			strcpy(cur_ptr->username, infonode->username);
			strcpy(cur_ptr->workplace, infonode->workplace);
			strcpy(cur_ptr->readername, infonode->readername);
			strcpy(cur_ptr->phonenumber, infonode->phonenumber);
			cur_ptr->availablebook = infonode->availablebook;
			cur_ptr->unavailablebook = infonode->unavailablebook;
		}
	}
	cur_ptr = NULL;
	free(cur_ptr);
}