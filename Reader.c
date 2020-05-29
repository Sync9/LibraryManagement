#include"Header.h"
void Reader(int ALT_Lev1, int ALT_Lev2,int UID,USER* UINF,READER* RINF,LOAR* LRINF, FILE* FP,FILE* FPMB, FILE* FPPI, FILE* FPBNI, FILE* FPBANI, BOOK* arr, int len, INDEX* arr_authorname, INDEX* arr_bookname, INDEX* arr_press) {
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
				if (ALT_Lev2 == 5) {
					USER* saved_info = (USER*)malloc(sizeof(USER));
					saved_info->UID = UID;
					printf("Please input the password you are to apply\n");
					scanf("%9s", &saved_info->Password);
					UINF = UserManagement_2_ModifyUserInformation(UINF, saved_info);
					free(saved_info);
				}
				else if (ALT_Lev2 == 1 || ALT_Lev2 == 3 || ALT_Lev2 == 2 || ALT_Lev2 == 4)  printf("Sorry,it's seems that you have no access to the feature:(\n");
				else if (ALT_Lev2 == 6);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}
		else if (ALT_Lev1 == 2 || ALT_Lev1 == 4) {
			printf("Sorry,it's seems that you have no access to the feature:(\n");
		}
		else if (ALT_Lev1 == 3) {
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
		else if (ALT_Lev1 == 4) {
			while (ALT_Lev2 != 2) {
				while (scanf_return != 1) {
					printf("**********************************\n1.Order\t\n2.BackToPrevious\t\n**********************************\n");
					scanf_return = scanf("%d", &ALT_Lev2);
					scanf("%*[^\n]");
					scanf("%*c");
					if (scanf_return != 1) printf("Please input the number you choosed again\n");
				}
				scanf_return = 0;
				if (ALT_Lev2 == 1) {
					LOAR* temp = (LOAR*)malloc(sizeof(LOAR));
					if (temp == NULL) {
						printf("Fail to apply for memory\n");
						exit(1);
					}
					else {
						while (scanf_return != 1) {
							printf("Plase input your readerID\n");
							scanf_return = scanf("%d", &temp->uid);
							if (temp->uid < 0) {
								printf("ID couldn't be a negative number\n");
								scanf_return = 0;
							}
							if (scanf_return != 1) printf("Please input your RecordID again\n");
						}
						scanf_return = 0;
						READER* CUR = RINF;
						while (CUR && CUR->UID != temp->uid) {
							CUR = CUR->NEXT;
						}
						if (CUR == NULL) {
							printf("Illegal ReaderID\n");
							continue;
						}
						else {
							if (CUR->AvailableBook == 0) {
								printf("Sorry.You couldn't borrow book beacause your avaliable book is 0\n");
								continue;
							}
							else {
								while (scanf_return != 1) {
									printf("Please input the BookID you are to order\n");
									scanf_return = scanf("%d", &temp->bookID);
									if (temp->bookID < 0) {
										printf("ID couldn't be a negative number\n");
										scanf_return = 0;
									}
									if (scanf_return != 1) printf("Please input the bookID again\n");
								}
								scanf_return = 0;
								BOOK* ptr = arr;
								for (; (ptr - arr) < len; ptr++) if (ptr->BookID == temp->bookID) break;
								if ((ptr - arr) == len) {
									printf("Illegal BookID\n");
									continue;
								}
								else {
									if (ptr->Total != ptr->LendOut) {
										printf("Please input the time you are goint to borrow\n");
										printf("YY/MM/DD\n");
										scanf("%11s", temp->lendout_date);
										CUR->AvailableBook = CUR->AvailableBook - 1;
										ptr->LendOut = ptr->LendOut + 1;
										AddNewNode(LRINF, temp);
										free(temp);
									}
									else {
										printf("Sorry,all the book has been lent out\n");
										continue;
									}
								}
							}
						}
					}
				}
				else if (ALT_Lev2 == 2);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}
		else if (ALT_Lev1 == 5);
		else printf("Illegal Input\nPlease input your choice again\n");
	}
	USER* CURU = (USER*)malloc(sizeof(USER));
	CURU = UINF->NEXT;
	while (CURU != NULL) {
		fwrite(CURU, sizeof(USER), 1, FP);
		CURU = CURU->NEXT;
	}
	USER* PREU = (USER*)malloc(sizeof(USER));
	while (CURU != NULL) {
		PREU = CURU;
		CURU = CURU->NEXT;
		free(PREU);
	}
	fclose(FP);
	if (arr != NULL) {
		fwrite(arr, sizeof(BOOK), len, FPMB);
		free(arr);
	}
	if (arr_bookname != NULL) {
		fwrite(arr_bookname, sizeof(INDEX), *cnt1, FPBNI);
		free(arr_bookname);
		free(cnt1);
	}
	if (arr_authorname != NULL) {
		fwrite(arr_authorname, sizeof(INDEX), *cnt2, FPBANI);
		free(arr_authorname);
		free(cnt2);
	}
	if (arr_press != NULL) {
		fwrite(arr_press, sizeof(INDEX), *cnt3, FPPI);
		free(arr_press);
		free(cnt3);
	}
	fclose(FPMB);
	fclose(FPPI);
	fclose(FPBNI);
	fclose(FPBANI);
	exit(0);
}
