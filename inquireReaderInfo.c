//tested
#include "Header.h"
void inquireReaderInfo(READER* head, READER* infonode) {
	READER* head_ptr = (READER*)malloc(sizeof(READER));
	head_ptr = head;
	if (head_ptr == NULL) printf("There is no reader in the system\n");
	else {
		while (head_ptr != NULL && strcmp(infonode->readername, head_ptr->readername) != 0) head_ptr = head_ptr->NEXT;
		if (head_ptr == NULL /*&& strcmp(infonode->readername, head_ptr->readername) != 0*/) printf("The reader isn't exist in the system\n");
		else {
			printf("%9s%9s%15s%12s%9s%9s\n", "Username", "Readername", "Workplace", "Phonenumber", "Availablebook", "Unavailablebook");
			controlFormat();
			printf("%9s%9s%15s%12s%9d%9d\n", head_ptr->username, head_ptr->readername, head_ptr->workplace, head_ptr->phonenumber, head_ptr->availablebook, head_ptr->unavailablebook);
		}
	}
	head_ptr = NULL;
	free(head_ptr);
}