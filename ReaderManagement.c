#include"Header.h"
READER* ReaderManagement_1_ReaderInformationInput(READER*Head,READER*RealNode) {
	READER* NewNode = (READER*)malloc(sizeof(READER));
	if (NewNode == NULL) {
		printf("Fail to apply for memory\n");
		exit(1);
	}
	else {
		NewNode->UID = RealNode->UID;
		strcpy(NewNode->Name, RealNode->Name);
		strcpy(NewNode->WorkPlace, RealNode->WorkPlace);
		strcpy(NewNode->PhoneNumber, RealNode->PhoneNumber);
		NewNode->AvailableBook = RealNode->AvailableBook;
		NewNode->UnAvailableBook = RealNode->UnAvailableBook;
		READER* CUR = (READER*)malloc(sizeof(READER));
		READER* PRE = (READER*)malloc(sizeof(READER));
		CUR = Head->NEXT;
		PRE = Head->NEXT;
		if (CUR == NULL) {
			Head->NEXT = NewNode;
			NewNode->NEXT = NULL;
		}
		else {
			while (CUR != NULL && CUR->Name[2] < NewNode->Name[2]) {
				PRE = CUR;
				CUR = CUR->NEXT;
			}
			if (PRE == CUR) Head->NEXT = NewNode;
			else  PRE->NEXT = NewNode;
			NewNode->NEXT = CUR;
		}
		return Head;
		free(CUR);
		free(PRE);
	}
}
READER* ReaderManagement_2_ModifyReaderInformation(READER* Head, READER* NewNode) {
		READER* CUR = (READER*)malloc(sizeof(READER));
		CUR = Head->NEXT;
		if (CUR == NULL) printf("There is no user in the System\n");
		else {
			while (CUR->NEXT != NULL && CUR->UID != NewNode->UID) CUR = CUR->NEXT;
			if (CUR->NEXT == NULL && CUR->UID != NewNode->UID) printf("The user isn't exist in the system\n");
			else {
				strcpy(CUR->Name, NewNode->Name);
				strcpy(CUR->WorkPlace, NewNode->WorkPlace);
				strcpy(CUR->PhoneNumber, NewNode->PhoneNumber);
				CUR->AvailableBook = NewNode->AvailableBook;
				CUR->UnAvailableBook = NewNode->UnAvailableBook;
			}
		}
		free(CUR);
}
READER* ReaderManagement_3_DeleteReaderInformation(READER* Head, READER* NewNode) {
	READER* CUR = (READER*)malloc(sizeof(READER));
	READER* PRE = (READER*)malloc(sizeof(READER));
		PRE = Head->NEXT;
		CUR = Head->NEXT;
		if (CUR == NULL) printf("There is no reader in the System\n");
		else {
			while (CUR->NEXT != NULL && CUR->UID != NewNode->UID) {
				PRE = CUR;
				CUR = CUR->NEXT;
			}
			if (CUR->NEXT == NULL && CUR->UID != NewNode->UID) printf("The reader isn't exist in the system\n");
			else PRE->NEXT = CUR->NEXT;
		}
		return Head;
		free(CUR);
		free(PRE);
}
READER* ReaderManagement_4_inidReaderInformation(READER* Head, READER* NewNode) {
	READER* CUR = (READER*)malloc(sizeof(READER));
		CUR = Head->NEXT;
		if (CUR == NULL) printf("There is no user in the System\n");
		else {
			while (CUR->NEXT != NULL && CUR->UID != NewNode->UID) CUR = CUR->NEXT;
			if (CUR->NEXT == NULL && CUR->UID != NewNode->UID) printf("The user isn't exist in the system\n");
			else printf("ReaderID = %d\tName = %s\tWorkPlace = %s\tPhoneNumber= %s\tAvailableBook= %d\tUnAvailableBook= %d\n", CUR->UID, CUR->Name, CUR->WorkPlace, CUR->PhoneNumber, CUR->AvailableBook, CUR->UnAvailableBook);
		}
		return Head;
		free(CUR);
}
READER* ReaderManagement_5_DisplayReaderInformation(READER* Head) {
	READER* CUR = (READER*)malloc(sizeof(READER));
		CUR = Head->NEXT;
		if (CUR == NULL) printf("There is no reader in the System\n");
		else {
			while (CUR != NULL) {
				printf("ReaderID = %d\tName = %s\tWorkPlace = %s\tPhoneNumber= %s\tAvailableBook= %d\tUnAvailableBook= %d\n", CUR->UID, CUR->Name, CUR->WorkPlace, CUR->PhoneNumber, CUR->AvailableBook, CUR->UnAvailableBook);
				CUR = CUR->NEXT;
			}
		}
		return Head;
		free(CUR);
}
