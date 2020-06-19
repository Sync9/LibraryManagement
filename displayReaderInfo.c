//tested
#include "Header.h"
void displayReaderInfo(READER* head) {
	READER* cur_ptr = (READER*)malloc(sizeof(READER));
	cur_ptr = head;
	if (cur_ptr == NULL) printf("There is no user info in the system\n");
	else {
		printf("%9s%9s%15s%12s%9s%9s\n","Username","Readername","Workplace","Phonenumber","Availablebook","Unavailablebook");
		while (cur_ptr != NULL) {
			controlFormat();
			printf("%9s%9s%15s%12s%9d%9d\n", cur_ptr->username, cur_ptr->readername, cur_ptr->workplace, cur_ptr->phonenumber, cur_ptr->availablebook, cur_ptr->unavailablebook);
			cur_ptr = cur_ptr->NEXT;
		}
	}
	free(cur_ptr);
}