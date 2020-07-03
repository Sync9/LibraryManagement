#include"Header.h"
int SignInAuthorize(USER* head, USER* signin,USER* root) {
	if (strcmp(root->name, signin->name) == 0) {
		if (root->UL != signin->UL) printf("Wrong UserLevel\n");
		if (strcmp(root->passwd, signin->passwd) != 0) printf("Wrong Password\n");
		if (strcmp(root->name, signin->name) == 0 && strcmp(root->passwd, root->passwd) == 0 && root->UL == signin->UL) {
			printf("Sign in successfully\n");
			return 1;
		}
	}
	else {
		USER* head_ptr = (USER*)malloc(sizeof(USER));
		head_ptr = head;
		while (head_ptr != NULL && strcmp(head_ptr->name, signin->name) != 0) head_ptr = head_ptr->NEXT;
		if (head_ptr == NULL) return 0;
		else {
			if (head_ptr->UL != signin->UL) printf("Wrong UserLevel\n");
			if (strcmp(head_ptr->name, signin->name) != 0) printf("Wrong Username\n");
			if (strcmp(head_ptr->passwd, signin->passwd) != 0) printf("Wrong Password\n");
			if (strcmp(head_ptr->name, signin->name) == 0 && strcmp(head_ptr->passwd, signin->passwd) == 0 && head_ptr->UL == signin->UL) {
				printf("Sign in successfully\n");
				system("reset");
				return 1;
			}
		}
	}
}
