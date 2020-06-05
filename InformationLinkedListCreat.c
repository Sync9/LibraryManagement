#include"Header.h"
USER* USERInformationLinkedListCreat(FILE* FP,char* path,USER* Head,USER* firstuser) {
		int c = fgetc(FP);
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
					head_ptr->NEXT = NewNode;
					head_ptr = head_ptr->NEXT;
					c = fgetc(FP);
				}
			fclose(FP);
			FP = fopen(path, "wb+");
		}
		else {
			fseek(FP, -1, SEEK_CUR);
			UserManagement_1_UserInformationInput(head_ptr, firstuser);
		}
		return Head;
		free(head_ptr);
}
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
LOAR* LOARInformationLinkedListCreat(FILE* FP, char* path, LOAR* Head) {
	LOAR* head_ptr = (LOAR*)malloc(sizeof(LOAR));
	head_ptr = Head;
	int cnt = 0;
	int c = fgetc(FP);
	if (c != EOF) {
		fseek(FP, -1, SEEK_CUR);
		c = fgetc(FP);
		while (c != EOF) {
			LOAR* NewNode = (LOAR*)malloc(sizeof(LOAR));
			NewNode->next = NULL;
			fseek(FP, -1, SEEK_CUR);
			fread(NewNode, sizeof(LOAR), 1, FP);
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
