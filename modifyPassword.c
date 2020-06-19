#include"Header.h"
USER* modifyPassword(USER* head, USER* infonode,USER* root) { 
	if (strcmp(root->name, "root")==0) {
		strcpy(root->passwd, infonode->passwd);
	}
	else {
		USER* cur_ptr = (USER*)malloc(sizeof(USER));
		cur_ptr = head;
		if (cur_ptr == NULL) printf("There is no user in the System\n");
		else {
			while (cur_ptr != NULL && cur_ptr->name != infonode->name) cur_ptr = cur_ptr->NEXT;
			if (cur_ptr == NULL) printf("The user isn't exist in the system\n");
			else {
				strcpy(cur_ptr->passwd, infonode->passwd);
			}
		}
		return head;
		free(cur_ptr);
	}
}