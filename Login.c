#include"Header.h"
int SignInAuthorize(USER* Head, USER* Signin) {
	USER* savedHead = (USER*)malloc(sizeof(USER));
	savedHead = Head;
	while (Head->NEXT!=NULL&&Head->UID!=Signin->UID) Head = Head->NEXT;
	if (Head->UL != Signin->UL) printf("Wrong UserLevel\n");
	if (Head->UID != Signin->UID) printf("Wrong UserID\n");
	if (strcmp(Head->Password, Signin->Password) != 0) printf("Wrong Password\n");
	if (Head->UID == Signin->UID && strcmp(Head->Password, Signin->Password) == 0 && Head->UL == Signin->UL) {
		printf("Sign in successfully\n");
		return 1;
	}
	Head = savedHead;
}
int Login(int cnt, USER* UINF, USER* Signin) {
	do {
		printf("Sign in as\n");
		printf("1----Reader\n");
		printf("2----SystemAdministrator\n");
		printf("3----LibraryAdministrator\n");
		scanf("%d", &Signin->UL);
		printf("Please Your UserID and Password\n");
		printf("Your UserID\n");
		scanf("%d", &Signin->UID);
		printf("Your Password\n");
		scanf("%s", Signin->Password);
		cnt++;
	} while (SignInAuthorize(UINF, Signin) != 1 && cnt != 3);
	if (cnt == 3) {
		printf("You have tried 3 times!System won't run.Please contact the Library Administrator to ask for help\n");
		printf("User information and book information has been saved\n");
		return 0;
	}
	else {
		printf("Sign in as UserID=%d\tUserLevel = %d\n", Signin->UID, Signin->UL);
		return 1;
	}
}