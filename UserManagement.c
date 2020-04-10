#include"Header.h"
USER* UserManagement_1_UserInformationInput(USER* Head, USER* RealNode) {
	USER* NewNode = (USER*)malloc(sizeof(USER));
	USER* CUR = (USER*)malloc(sizeof(USER));
	USER* PRE = (USER*)malloc(sizeof(USER));
	NewNode->UID = RealNode->UID;
	strcpy(NewNode->Password, RealNode->Password);
	NewNode->UL = RealNode->UL;
	NewNode->NEXT = NULL;
	CUR = Head->NEXT;
	PRE = Head->NEXT;
	if (CUR == NULL) {
		Head->NEXT = NewNode;
		NewNode->NEXT = NULL;
	}
	else {
		while (CUR != NULL && CUR->UID < NewNode->UID) {
			PRE = CUR;
			CUR = CUR->NEXT;
		}
		if (PRE == CUR) Head->NEXT = NewNode;
		else PRE->NEXT = NewNode;
		NewNode->NEXT = CUR;
	}
	return Head;
	free(CUR);
	free(PRE);
}
USER* UserManagement_2_ModifyUserInformation(USER* Head, USER* NewNode) {
	USER* CUR = (USER*)malloc(sizeof(USER));
		CUR = Head->NEXT;
		if (CUR == NULL) printf("There is no user in the System\n");
		else {
			while (CUR->NEXT != NULL && CUR->UID != NewNode->UID) CUR = CUR->NEXT;
			if (CUR->NEXT == NULL && CUR->UID != NewNode->UID) printf("The user isn't exist in the system\n");
			else {
				strcpy(CUR->Password, NewNode->Password);
				CUR->UL = NewNode->UL;
			}
		}
		return Head;
		free(CUR);
}
USER* UserManagement_3_DeleteUserInformation(USER* Head, USER* NewNode) {
	USER* CUR = (USER*)malloc(sizeof(USER));
	USER* PRE = (USER*)malloc(sizeof(USER));
		PRE = Head->NEXT;
		CUR = Head->NEXT;
		if (CUR == NULL) printf("There is no user in the System\n");
		else {
			while (CUR->NEXT != NULL && CUR->UID != NewNode->UID) {
				PRE = CUR;
				CUR = CUR->NEXT;
			}
			if (CUR->NEXT == NULL && CUR->UID != NewNode->UID) printf("The user isn't exist in the system\n");
			else PRE->NEXT = CUR->NEXT;
		}
		return Head;
		free(CUR); 
		free(PRE);
}
USER* UserManagement_4_DisplayUserInformation(USER* Head) {
	USER* CUR = (USER*)malloc(sizeof(USER));
		CUR = Head->NEXT;
		while (CUR != NULL) {
			printf("UserID = %d\tPassword = %s\tUserLevel = %d\n", CUR->UID, CUR->Password, CUR->UL);
			CUR = CUR->NEXT;
		}
		return Head;
		free(CUR);
}
USER* UserManagement_5_ModifyUserPassword(USER* Head, USER* NewNode) {
	USER* CUR = (USER*)malloc(sizeof(USER));
	CUR = Head->NEXT;
	if (CUR == NULL) printf("There is no user in the System\n");
	else {
		while (CUR->NEXT != NULL && CUR->UID != NewNode->UID) CUR = CUR->NEXT;
		if (CUR->NEXT == NULL && CUR->UID != NewNode->UID) printf("The user isn't exist in the system\n");
		else {
			strcpy(CUR->Password, NewNode->Password);
		}
	}
	return Head;
	free(CUR);
}