#include"Header.h"
void SystemAdministrator(int ALT_Lev1, int ALT_Lev2, USER* UINF, FILE* FP, FILE* FPMB, FILE* FPPI, FILE* FPBNI, FILE* FPBANI, BOOK* arr, int len, INDEX* arr_authorname, INDEX* arr_bookname, INDEX* arr_press) {
	int* cnt1 = (int*)malloc(sizeof(int));
	if (cnt1 == NULL) {
		printf("Fail to apply for memory\n");
		exit(1);
	}
	int* cnt2 = (int*)malloc(sizeof(int));
	if (cnt2 == NULL) {
		printf("Fail to apply for memory\n");
		exit(1);
	}
	int* cnt3 = (int*)malloc(sizeof(int));
	if (cnt3 == NULL) {
		printf("Fail to apply for memory\n");
		exit(1);
	}
	while (ALT_Lev1 != 5) {
		ALT_Lev1 = 0;
		ALT_Lev2 = 0;
		int scanf_return = 0;
		while (scanf_return != 1) {
			printf("**********************************\n\t1.UserManagement\n\t2.ReaderManagement\n\t3.BookManagement\n\t4.BookCirculationManagement\n\t5.Exit\n***********************************\n");
			scanf_return = scanf("%d", &ALT_Lev1);
			scanf("%*[^\n]");
			scanf("%*c");
			if (scanf_return != 1) printf("Please input the number you choosed again\n");
		}
		scanf_return = 0;
		if (ALT_Lev1 == 1) {
			while (ALT_Lev2 != 6) {
				while (scanf_return != 1) {
					printf("**********************************\n\t1.InputUserInformation\n\t2.ModifyUserInformation\n\t3.DeleteUserInformation\n\t4.DisplayUserInformation\n\t5.ModifyUserPassword\n\t6.BackToPrevious\n***********************************\n");
					scanf_return = scanf("%d", &ALT_Lev2);
					scanf("%*[^\n]");
					scanf("%*c");
					if (scanf_return != 1) printf("Please input the number you choosed again\n");
				}
				scanf_return = 0;
				USER* saved_info = (USER*)malloc(sizeof(USER));
				if (cnt1 == NULL) {
					printf("Fail to apply for memory\n");
					exit(1);
				}
				else {
					if (ALT_Lev2 == 1) {
						while (scanf_return != 1) {
							printf("Please input the UserID you wanna input\n");
							scanf_return = scanf("%d", &saved_info->UID);
							scanf("%*[^\n]");
							scanf("%*c");
							if (saved_info->UID < 0) {
								printf("UserID couldn't be a negative number\n");
								scanf_return = 0;
							}
							if (scanf_return != 1) printf("Please input the UserID again\n");
						}
						scanf_return = 0;
						printf("Please input the Password\n");
						scanf("%9s", saved_info->Password);
						while (scanf_return != 1) {
							printf("Please input the UserLevel\n");
							printf("1----Reader\n");
							printf("2----SystemAdministrator\n");
							printf("3----LibraryAdministrator\n");
							scanf_return = scanf("%d", &saved_info->UL);
							if (saved_info->UL != 1 || saved_info->UL != 2 || saved_info->UL != 3) {
								printf("Please pick your chioce from follows number again\n");
								printf("1----Reader\n");
								printf("2----SystemAdministrator\n");
								printf("3----LibraryAdministrator\n");
								scanf_return = 0;
							}
							if (scanf_return != 1) printf("Please input your choice again\n");
						}
						scanf_return = 0;
						UINF = UserManagement_1_UserInformationInput(UINF, saved_info);
					}
					else if (ALT_Lev2 == 2) {
						while (scanf_return != 1) {
							printf("Please input the UserID you wanna modify\n");
							scanf_return = scanf("%d", &saved_info->UID);
							scanf("%*[^\n]");
							scanf("%*c");
							if (saved_info->UID < 0) {
								printf("UserID couldn't be a negative number\n");
								scanf_return = 0;
							}
							if (scanf_return != 1) printf("Please input the UserID again\n");
						}
						scanf_return = 0;
						printf("Please input the Password\n");
						scanf("%9s", saved_info->Password);
						while (scanf_return != 1) {
							printf("Please input the UserLevel\n");
							printf("1----Reader\n");
							printf("2----SystemAdministrator\n");
							printf("3----LibraryAdministrator\n");
							scanf_return = scanf("%d", &saved_info->UL);
							if (saved_info->UL != 1 || saved_info->UL != 2 || saved_info->UL != 3) {
								printf("Please pick your chioce from follows number again\n");
								printf("1----Reader\n");
								printf("2----SystemAdministrator\n");
								printf("3----LibraryAdministrator\n");
								scanf_return = 0;
							}
							if (scanf_return != 1) printf("Please input your choice again\n");
						}
						scanf_return = 0;
						UINF = UserManagement_2_ModifyUserInformation(UINF, saved_info);
					}
					else if (ALT_Lev2 == 3) {
						while (scanf_return != 1) {
							printf("Whose password are you going to Delete?\nPlease input his/her UserID\n");
							scanf_return = scanf("%d", &saved_info->UID);
							scanf("%*[^\n]");
							scanf("%*c");
							if (saved_info->UID < 0) {
								printf("UserID couldn't be a negative number\n");
								scanf_return = 0;
							}
							if (scanf_return != 1) printf("Please input the UserID again\n");
						}
						scanf_return = 0;
						UINF = UserManagement_3_DeleteUserInformation(UINF, saved_info);
					}
					else if (ALT_Lev2 == 4) {
						UINF = UserManagement_4_DisplayUserInformation(UINF);
					}
					else if (ALT_Lev2 == 5) {
						while (scanf_return != 1) {
							printf("Whose password are you going to change?\nPlease input his/her UserID\n");
							scanf_return = scanf("%d", &saved_info->UID);
							scanf("%*[^\n]");
							scanf("%*c");
							if (saved_info->UID < 0) {
								printf("UserID couldn't be a negative number\n");
								scanf_return = 0;
							}
							if (scanf_return != 1) printf("Please input the UserID again\n");
						}
						scanf_return = 0;
						printf("Please input the password you are to apply\n");
						scanf("%9s", saved_info->Password);
						UINF = UserManagement_5_ModifyUserPassword(UINF, saved_info);
					}
					else if (ALT_Lev2 == 6);
					else printf("Illegal Input\nPlease input your choice again\n");
					free(saved_info);
				}
			}
		}
		else if (ALT_Lev1 == 2 || ALT_Lev1 == 3) {
			printf("Sorry,it's seems that you have no access to the feature:(\n");
		}
		else if (ALT_Lev1 == 4) {
			while (ALT_Lev2 != 5) {
				if (arr == NULL) {
					*cnt1 = 0;
					*cnt2 = 0;
					*cnt3 = 0;
				}
				else {
					INDEX* temp = (INDEX*)malloc(sizeof(INDEX));
					if (temp == NULL) {
						printf("Fail to apply for memory\n");
						exit(1);
					}
					else {
						temp = CreatIndex(arr, len, arr_bookname, cnt1, 1);
						INDEX* bookname = (INDEX*)malloc(sizeof(INDEX) * *cnt1);
						if (bookname == NULL) {
							printf("Fail to apply for memory\n");
							exit(1);
						}
						else {
							INDEX* ptr = bookname;
							for (INDEX* ptr_temp = temp; (ptr_temp - temp) < *cnt1; ptr_temp++, ptr++) {
								strcpy(ptr->str, ptr_temp->str);
								ptr->ini = ptr_temp->ini;
								ptr->len = ptr_temp->len;
							}
							arr_bookname = bookname;
						}
						temp = CreatIndex(arr, len, arr_authorname, cnt2, 2);
						INDEX* authorname = (INDEX*)malloc(sizeof(INDEX) * *cnt2);
						if (authorname == NULL) {
							printf("Fail to apply for memory\n");
							exit(1);
						}
						else {
							INDEX* ptr = authorname;
							for (INDEX* ptr_temp = temp; (ptr_temp - temp) < *cnt2; ptr_temp++, ptr++) {
								strcpy(ptr->str, ptr_temp->str);
								ptr->ini = ptr_temp->ini;
								ptr->len = ptr_temp->len;
							}
							arr_authorname = authorname;
						}
						temp = CreatIndex(arr, len, arr_press, cnt3, 3);
						INDEX* press = (INDEX*)malloc(sizeof(INDEX) * *cnt2);
						if (press == NULL) {
							printf("Fail to apply for memory\n");
							exit(1);
						}
						else {
							INDEX* ptr = press;
							for (INDEX* ptr_temp = temp; (ptr_temp - temp) < *cnt3; ptr_temp++, ptr++) {
								strcpy(ptr->str, ptr_temp->str);
								ptr->ini = ptr_temp->ini;
								ptr->len = ptr_temp->len;
							}
							arr_press = press;
						}
						free(temp);
					}
				}
				while (scanf_return != 1) {
					printf("**************************************\n\t1.InputBookInformation\n\t2.ModifyBookInformation\n\t3.InquireBookInformation\n\t4.TotalStatistics\n\t5.BackToPrevious\n**************************************\n");
					scanf_return = scanf("%d", &ALT_Lev2);
					scanf("%*[^\n]");
					scanf("%*c");
					if (scanf_return != 1) printf("Please input the number you choosed again\n");
				}
				scanf_return = 0;
				if (ALT_Lev2 == 1 || ALT_Lev2 == 2) printf("Sorry,it's seems that you have no access to the feature:(\n");
				else if (ALT_Lev2 == 3) {
					int ALT_Lev3 = 0;
					while (ALT_Lev3 != 5) {
						int next = 0;
						int cnt_temp = 0;
						int index_len = 0;
						int hit = 0;
						int ini = 0;
						while (scanf_return != 1) {
							printf("**************************************\n\t1.By RecordID\n\t2.By BookName\n\t3.By AuthorName\n\t4.By Press\n\t5.BackToPrevious\n**************************************\n");
							scanf_return = scanf("%d", &ALT_Lev3);
							scanf("%*[^\n]");
							scanf("%*c");
							if (scanf_return != 1) printf("Please input the number you choosed again\n");
						}
						scanf_return = 0;
						if (ALT_Lev3 == 1) {
							if (arr == NULL) printf("There is no information\n");
							else {
								BOOK* temp = (BOOK*)malloc(sizeof(BOOK));
								if (temp == NULL) {
									printf("Fail to apply for memory\n");
									exit(1);
								}
								else {
									int offset = 0;
									while (scanf_return != 1) {
										printf("Please input the recordID you are to inquire\n");
										scanf_return = scanf("%d", &temp->RecordID);
										scanf("%*[^\n]");
										scanf("%*c");
										if (temp->RecordID < 0) {
											printf("ID couldn't be a negative number\n");
											scanf_return = 0;
										}
										if (scanf_return != 1) printf("Please input the RecordID again\n");
									}
									scanf_return = 0;
									InsertionSort(arr, len);
									offset = BinarySearch(arr, len, temp->RecordID);
									if (offset == -1) printf("The item isn't exsist\n");
									else {
										temp->BookID = arr[offset].BookID;
										temp->LendOut = arr[offset].LendOut;
										temp->Total = arr[offset].Total;
										strcpy(temp->AuthorName, arr[offset].AuthorName);
										strcpy(temp->BookName, arr[offset].BookName);
										strcpy(temp->Press, arr[offset].Press);
										printf("RecordID\tBookID\tBookName\tAuthorName\tPress\tLendOut\tTotal\t\n");
										printf("%d\t%d\t%s\t%s\t%s\t%d\t%d\t\n", temp->RecordID, temp->BookID, temp->BookName, temp->AuthorName, temp->Press, temp->LendOut, temp->Total);
									}
									free(temp);
								}
							}
						}
						else if (ALT_Lev3 == 2) {
							if (*cnt2 == 0) printf("There is no information\n");
							else {
								char* input = (char*)malloc(sizeof(char) * 9);
								if (input == NULL) {
									printf("Fail to apply for memory\n");
									exit(1);
								}
								else {
									printf("Please input the book name you are to inquire\n");
									scanf("%9s", input);
									PrintInquireResult(arr, arr_bookname, cnt1, input, next, cnt_temp, index_len, hit, ini, len);
									free(input);
								}
							}
						}
						else if (ALT_Lev3 == 3) {
							if (*cnt2 == 0) printf("There is no information\n");
							else {
								ini = 0;
								char* input = (char*)malloc(sizeof(char) * 9);
								if (input == NULL) {
									printf("Fail to apply for memory\n");
									exit(1);
								}
								else {
									printf("Please input the author name you are to inquire\n");
									scanf("%9s", input);
									PrintInquireResult(arr, arr_authorname, cnt2, input, next, cnt_temp, index_len, hit, ini, len);
									free(input);
								}
							}
						}
						else if (ALT_Lev3 == 4) {
							if (*cnt3 == 0) printf("There is no information\n");
							else {
								ini = 0;
								char* input = (char*)malloc(sizeof(char) * 9);
								if (input == NULL) {
									printf("Fail to apply for memory\n");
									exit(1);
								}
								else {
									printf("Please input the press you are to inquire\n");
									scanf("%9s", input);
									PrintInquireResult(arr, arr_press, cnt3, input, next, cnt_temp, index_len, hit, ini, len);
									free(input);
								}
							}
						}
						else if (ALT_Lev3 == 5);
						else printf("Illegal Input\nPlease input your choice again\n");
					}
				}
				else if (ALT_Lev2 == 4) {
					if (arr == NULL) printf("There is no information\n");
					else {
						printf("************************\n\tTotalStatistics\t\n**************************\n");
						printf("RecordID\tBookID\tBookName\tAuthorName\tPress\tLendOut\tTotal\t\n");
						for (BOOK* ptr = arr; (ptr - arr) < len; ptr++)
							printf("%d\t%d\t%s\t%s\t%s\t%d\t%d\t\n", ptr->RecordID, ptr->BookID, ptr->BookName, ptr->AuthorName, ptr->Press, ptr->LendOut, ptr->Total);
					}
				}
				else if (ALT_Lev2 == 5);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}
		else if (ALT_Lev1 == 5);
		else printf("Illegal Input\nPlease input your choice again\n");
	}
	USER* CURU = (USER*)malloc(sizeof(USER));
	if (CURU == NULL) {
		printf("Fail to apply for memory\n");
		exit(1);
	}
	else {
		CURU = UINF->NEXT;
		while (CURU != NULL) {
			fwrite(CURU, sizeof(USER), 1, FP);
			CURU = CURU->NEXT;
		}
		USER* PREU = (USER*)malloc(sizeof(USER));
		if (PREU == NULL) {
			printf("Fail to apply for memory\n");
			exit(1);
		}
		else {
			while (CURU != NULL) {
				PREU = CURU;
				CURU = CURU->NEXT;
				free(PREU);
			}
			fclose(FP);
		}
	}
	exit(0);
}
