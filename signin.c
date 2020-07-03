#include"Header.h"
int signIn(USER* head,USER* signin,USER* root) {
	int cnt = 0;
	do {
		Center();
		controlFormat();
		Astrisk();
		controlFormat();
		printf("Sign in as\n");
		controlFormat();
		printf("1----Reader\n");
		controlFormat();
		printf("2----SystemAdministrator\n");
		controlFormat();
		printf("3----LibraryAdministrator\n");
		controlFormat();
		Astrisk();
		controlFormat();
		scanf("%d", &signin->UL);
		controlFormat();
		printf("Please Your UserID and Password\n");
		controlFormat();
		printf("Your UserID\n");
		controlFormat();
		scanf("%9s", signin->name);
		controlFormat();
		printf("Your Password\n");
		controlFormat();
		system("stty -echo");
		scanf("%9s",signin->passwd);
		system("stty echo");
		controlFormat();
		Astrisk();
		system("reset");
		cnt++;
	} while (SignInAuthorize(head,signin,root) != 1 && cnt != 3);
	if (cnt == 3) {
		Center();
		controlFormat();
		Astrisk();
		controlFormat();
		printf("You have tried 3 times!System won't run.\n");
		controlFormat();
		printf("Please contact the Library Administrator to ask for help\n");
		controlFormat();
		printf("Infomation has been saved\n");
		controlFormat();
		Astrisk();
		return 0;
	}
	else {
		return 1;
	}
}
