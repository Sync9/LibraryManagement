#include"Header.h"
USER* USERInformationLinkedListCreat(FILE* FP,char* path,USER* Head) {
		int c = fgetc(FP);
		int cnt = 0;
		USER* head_ptr = (USER*)malloc(sizeof(USER));
		head_ptr = Head;
		if (c != EOF) {
			fseek(FP, -1, SEEK_CUR);
			c = fgetc(FP);
				while (c != EOF) {
					USER* NewNode = (USER*)malloc(sizeof(USER));
					NewNode->NEXT = NULL;
					fseek(FP, -1, SEEK_CUR);
					fread(NewNode, sizeof(USER), 1, FP);
					if (cnt == 0) { 
						head_ptr->NEXT = NewNode;
						head_ptr = head_ptr->NEXT;
						cnt++;
					}
					else head_ptr->NEXT = NewNode;
					c = fgetc(FP);
				}
			fclose(FP);
			FP = fopen(path, "wb+");
		}
		else {
			fseek(FP, -1, SEEK_CUR);
			USER* FirstUser = (USER*)malloc(sizeof(USER));
			head_ptr->NEXT = NULL;
			printf("It seems that it's your first time to run the system:)\n");
			printf("There is no user in the System\n");
			printf("Don't worry,I will help you become the first System Administrator:)\n");
			FirstUser->UL = 2;
			printf("Now Please input your UserID\n");
			scanf("%d", &FirstUser->UID);
			printf("Your Password\n");
			scanf("%s", FirstUser->Password);
			printf("%s is your Password", FirstUser->Password);
			printf("Congratulations! You have become the fist System Administrator\n");
			UserManagement_1_UserInformationInput(head_ptr, FirstUser);
		}
		return Head;
		free(head_ptr);
}
READER* READERInformationLinkedListCreat(FILE*FP,char* path,READER* Head){
		READER* head_ptr = (READER*)malloc(sizeof(READER));
		head_ptr = Head;
		int cnt = 0;
		int c = fgetc(FP);
		if (c != EOF) {
			fseek(FP, -1, SEEK_CUR);
			c = fgetc(FP);
			while (c != EOF) {
				READER* NewNode = (READER*)malloc(sizeof(READER));
				NewNode->NEXT = NULL;
				fseek(FP, -1, SEEK_CUR);
				fread(NewNode, sizeof(READER), 1, FP);
				if (cnt == 0) {
					head_ptr->NEXT = NewNode;
					head_ptr = head_ptr->NEXT;
					cnt++;
				}
				else head_ptr->NEXT = NewNode;
				c = fgetc(FP);
			}
			fclose(FP);
			FP = fopen(path, "wb+");
		}
		else {
			fseek(FP, -1, SEEK_CUR);
			head_ptr->NEXT=NULL;
		}
		return Head;
		free(head_ptr);
}
LendOutAndReturn* LendOutAndReturnInformationLinkedListCreat(FILE* FP, char* path, LendOutAndReturn* Head) {
	LendOutAndReturn* head_ptr = (LendOutAndReturn*)malloc(sizeof(LendOutAndReturn));
	head_ptr = Head;
	int cnt = 0;
	int c = fgetc(FP);
	if (c != EOF) {
		fseek(FP, -1, SEEK_CUR);
		c = fgetc(FP);
		while (c != EOF) {
			LendOutAndReturn* NewNode = (LendOutAndReturn*)malloc(sizeof(LendOutAndReturn));
			NewNode->next = NULL;
			fseek(FP, -1, SEEK_CUR);
			fread(NewNode, sizeof(LendOutAndReturn), 1, FP);
			if (cnt == 0) {
				head_ptr->next = NewNode;
				head_ptr = head_ptr->next;
				cnt++;
			}
			else head_ptr->next = NewNode;
			c = fgetc(FP);
		}
		fclose(FP);
		FP = fopen(path, "wb+");
	}
	else {
		fseek(FP, -1, SEEK_CUR);
		head_ptr->next = NULL;
	}
	return Head;
	free(head_ptr);
}