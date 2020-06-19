//--tested
#include "Header.h"
void displayUserInfo(USER* head) {
	USER* cur_ptr = (USER*)malloc(sizeof(USER));
	cur_ptr = head;
	if (cur_ptr == NULL) {
		printf("There is no user info in the system\n");
	}
	else {
		controlFormat();
		printf("%9s%9s%9s\n", "UserID", "Password", "UserLevel");
		while (cur_ptr != NULL) { 
			controlFormat();
			printf("%9s%9s%9d\n", cur_ptr->name, cur_ptr->passwd, cur_ptr->UL);
			cur_ptr = cur_ptr->NEXT;
		}
	}
	free(cur_ptr);
}