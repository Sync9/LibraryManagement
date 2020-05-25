#include"Header.h"
int SignInAuthorize(USER* Head, USER* Signin) {
	
	while (Head->NEXT!=NULL&&Head->UID!=Signin->UID) Head = Head->NEXT;
	if (Head->UID == Signin->UID && strcmp(Head->Password, Signin->Password) == 0 && Head->UL == Signin->UL) {
		printf("Sign in successfully\n");
		return 1;
	}
	else if (Head->UID == Signin->UID && strcmp(Head->Password, Signin->Password) == 0 && Head->UL != Signin->UL) {
		printf("Wrong UserLevel\n");
	}
	else if (Head->UID == Signin->UID && strcmp(Head->Password, Signin->Password) != 0 && Head->UL == Signin->UL) {
		printf("Wrong Password\n");
	}
	else if (Head->UID != Signin->UID && strcmp(Head->Password, Signin->Password) == 0 && Head->UL == Signin->UL) {
		printf("Wrong UserID\n");
	}
	else if (Head->UID != Signin->UID && strcmp(Head->Password, Signin->Password) != 0 && Head->UL == Signin->UL) {
		printf("Wrong UserID\n");
		printf("Wrong Password\n");
	}
	else if (Head->UID != Signin->UID && strcmp(Head->Password, Signin->Password) == 0 && Head->UL != Signin->UL) {
		printf("Wrong UserID\n");
		printf("Wrong UserLevel\n");
	}
	else if (Head->UID == Signin->UID && strcmp(Head->Password, Signin->Password) != 0 && Head->UL != Signin->UL) {
		printf("Wrong Password\n");
		printf("Wrong UserLevel\n");
	}
	else {
		printf("Wrong UserID\n");
		printf("Wrong Password\n");
		printf("Wrong UserLevel\n");
	}
}
int Login(int cnt, USER* UINF, USER* Signin) {
	do {
		printf("Sign in as\n");
		printf("1----Reader\n");
		printf("2----SystemAdministrator\n");
		printf("3----LibraryAdministrator\n");
		scanf("%d", &Signin->UL);
		printf("Please input Your UserID and Password\n");
		printf("Your UserID\n");
		scanf("%d", &Signin->UID);
		printf("Your Password\n");
		scanf("%s", Signin->Password);
		cnt++;
	} while (SignInAuthorize(UINF, Signin) != 1 && cnt != 3);
	if (cnt == 3) {
		printf("You have tried 3 times!System won't run.Please contact the Library Administrator to ask for help\n");
		return 0;
	}
	else {
		printf("Sign in as UserID=%d\tUserLevel = %d\n", Signin->UID, Signin->UL);
		return 1;
	}
}
