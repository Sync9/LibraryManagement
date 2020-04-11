#include"Header.h"
void LibraryAdministrator(int ALT_Lev1, int ALT_Lev2, USER* UINF, READER* RINF, LOAR* LRINF, FILE* FPU, FILE* FPR, FILE* FPMB, FILE* FPPI, FILE* FPBNI, FILE* FPBANI, FILE* FPLR,BOOK* arr, int len, INDEX* arr_authorname, INDEX* arr_bookname, INDEX* arr_press) {
	int* cnt1 = (int*)malloc(sizeof(int));
	int* cnt2 = (int*)malloc(sizeof(int));
	int* cnt3 = (int*)malloc(sizeof(int));
	while (ALT_Lev1 != 5) {
		ALT_Lev1 = 0;
		ALT_Lev2 = 0;
		int time = 1;
		printf("**********************************\n\t1.UserManagement\n\t2.ReaderManagement\n\t3.BookManagement\n\t4.BookCirculationManagement\n\t5.Exit\n***********************************\n");
		scanf("%d", &ALT_Lev1);
		if (ALT_Lev1 == 1) {
			while (ALT_Lev2 != 6) {
				printf("**********************************\n\t1.InputUserInformation\n\t2.ModifyUserInformation\n\t3.DeleteUserInformation\n\t4.DisplayUserInformation\n\t5.ModifyUserPassword\n\t6.BackToPrevious\n***********************************\n");
				scanf("%d", &ALT_Lev2);
				if (ALT_Lev2 == 2) {
					USER* saved_info = (USER*)malloc(sizeof(USER));
					printf("Whose password are you going to change?\nPlease input his/her UserID\n");
					scanf("%d", &saved_info->UID);
					printf("Please input the password you are to apply\n");
					scanf("%s", saved_info->Password);
					UserManagement_2_ModifyUserInformation(UINF, saved_info);
					free(saved_info);
				}
				else if (ALT_Lev2 == 1 || ALT_Lev2 == 3 || ALT_Lev2 == 4 || ALT_Lev2 == 5)  printf("Sorry,it's seems that you have no access to the feature:(\n");
				else if (ALT_Lev2 == 6);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}/*Paraments ReaderMangament(int ALT, READER* Head, int* RID, char* Name, char* WorkPlace, char* PhoneNumber, int* AvailableBook, int* UnAvailableBook)*/
		else if (ALT_Lev1 == 2) {
			while (ALT_Lev2 != 6) {
				printf("**********************************\n\t1.InputReaderInformation\n\t2.ModifyReaderInformation\n\t3.DeleteReaderInformation\n\t4.inidReaderInformation\n\t5.DisplayReaderInformation\n\t6.BackToPrevious\n***********************************\n");
				scanf("%d", &ALT_Lev2);
				READER* saved_info = (READER*)malloc(sizeof(READER));
				if (ALT_Lev2 == 1) {
					printf("Please input the ReaderID you wanna input\n");
					scanf("%d", &saved_info->UID);
					printf("Please input the Name\n");
					scanf("%s", saved_info->Name);
					printf("Please input the WorkPlace\n");
					scanf("%s", saved_info->WorkPlace);
					printf("Please input the PhoneNumber\n");
					scanf("%s", saved_info->PhoneNumber);
					printf("Please input the AvailableBook\n");
					scanf("%d", &saved_info->AvailableBook);
					printf("Please input the AvailableBook\n");
					scanf("%d", &saved_info->UnAvailableBook);
					RINF=ReaderManagement_1_ReaderInformationInput(RINF,saved_info);
				}
				else if (ALT_Lev2 == 2) {
					READER* saved_info = (READER*)malloc(sizeof(READER));
					printf("Please input the ReaderID you wanna input\n");
					scanf("%d", &saved_info->UID);
					printf("Please input the Name\n");
					scanf("%s", saved_info->Name);
					printf("Please input the WorkPlace\n");
					scanf("%s", saved_info->WorkPlace);
					printf("Please input the PhoneNumber\n");
					scanf("%s", saved_info->PhoneNumber);
					printf("Please input the AvailableBook\n");
					scanf("%d", &saved_info->AvailableBook);
					printf("Please input the UnAvailableBook\n");
					scanf("%d", &saved_info->UnAvailableBook);
					RINF=ReaderManagement_2_ModifyReaderInformation(RINF, saved_info);
				}
				else if (ALT_Lev2 == 3) {

					printf("Which reader are you going to Delete?\nPlease input his/her ReaderID\n");
					scanf("%d", &saved_info->UID);
					RINF=ReaderManagement_3_DeleteReaderInformation(RINF,saved_info);

				}
				else if (ALT_Lev2 == 4) {
	
					printf("Which reader are you going to inid?\nPlease input his/her ReaderID\n");
					scanf("%d", &saved_info->UID);
					RINF=ReaderManagement_4_inidReaderInformation(RINF,saved_info);
				}
				else if (ALT_Lev2 == 5) {
					RINF=ReaderManagement_5_DisplayReaderInformation(RINF);
				}
				else if (ALT_Lev2 == 6);
				else printf("Illegal Input\nPlease input your choice again\n");
				free(saved_info);
			}
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
					temp = CreatIndex(arr, len, arr_bookname, cnt1,1);
					INDEX* bookname = (INDEX*)malloc(sizeof(INDEX) * *cnt1);
					INDEX* ptr = bookname;
					for (INDEX* ptr_temp = temp; (ptr_temp - temp) < *cnt1; ptr_temp++, ptr++){
						strcpy(ptr->str, ptr_temp->str);
						ptr->ini = ptr_temp->ini;
						ptr->len = ptr_temp->len;
					}
					arr_bookname = bookname;
					temp = CreatIndex(arr, len, arr_authorname,cnt2, 2);
					INDEX* authorname = (INDEX*)malloc(sizeof(INDEX) * *cnt2);
					ptr = authorname;
					for (INDEX* ptr_temp = temp; (ptr_temp - temp) < *cnt2; ptr_temp++, ptr++){
						strcpy(ptr->str, ptr_temp->str);
						ptr->ini = ptr_temp->ini;
						ptr->len = ptr_temp->len;
					}
					arr_authorname = authorname;
					temp = CreatIndex(arr, len, arr_press, cnt3,3);
					INDEX* press = (INDEX*)malloc(sizeof(INDEX) * *cnt2);
					ptr = press;
					for (INDEX* ptr_temp = temp; (ptr_temp - temp) < *cnt3; ptr_temp++, ptr++) {
						strcpy(ptr->str, ptr_temp->str);
						ptr->ini = ptr_temp->ini;
						ptr->len = ptr_temp->len;
					}
					arr_press = press;
					free(temp);
				}		
				printf("**************************************\n\t1.InputBookInformation\n\t2.ModifyBookInformation\n\t3.InquireBookInformation\n\t4.TotalStatistics\n\t5.BackToPrevious\n**************************************\n");
				scanf("%d", &ALT_Lev2);
				if (ALT_Lev2 == 1) {
					if (arr == NULL) arr = (BOOK*)malloc(sizeof(BOOK));
					BOOK* saved_info = (BOOK*)malloc(sizeof(BOOK));
					printf("Please input the RecordID\n");
					scanf("%d", &saved_info->RecordID);
					printf("Please input the BookID\n");
					scanf("%d", &saved_info->BookID);
					printf("Please input the book name\n");
					scanf("%s", saved_info->BookName);
					printf("Please input the author name\n");
					scanf("%s", saved_info->AuthorName);
					printf("Please input the press name\n");
					scanf("%s", saved_info->Press);
					printf("Please input the number of the book lent out\n");
					scanf("%d", &saved_info->LendOut);
					printf("Please input the sum of the book\n");
					scanf("%d", &saved_info->Total);
					arr = BookManagement_1_BookInformationInput(arr, saved_info, len, 1);
					len++;
					free(saved_info);
				}
				else if (ALT_Lev2 == 2) {
					if (arr == NULL) printf("There is no information\n");
					else {
						BOOK* saved_info = (BOOK*)malloc(sizeof(BOOK));
						printf("Please input the RecordID you are to modify\n");
						scanf("%d", &saved_info->RecordID);
						printf("Please input the number of the book lent out\n");
						scanf("%d", &saved_info->LendOut);
						printf("Please input the sum of the book\n");
						scanf("%d", &saved_info->Total);
						free(saved_info);
					}
				}
				else if (ALT_Lev2 == 3) {
					int ALT_Lev3 = 0;
					while (ALT_Lev3 != 5) {
						int next = 0;
						int cnt_temp = 0;
						int index_len = 0;
						int hit = 0;
						int ini = 0;
						printf("**************************************\n\t1.By RecordID\n\t2.By BookName\n\t3.By AuthorName\n\t4.By Press\n\t5.BackToPrevious\n**************************************\n");
						scanf("%d", &ALT_Lev3);
						if (ALT_Lev3 == 1) {
							if (arr == NULL) printf("There is no information\n");
							else {
								BOOK* temp = (BOOK*)malloc(sizeof(BOOK));
								int offset = 0;
								printf("Please input the recordID you are to inquire\n");
								scanf("%d", &temp->RecordID);
								InsertionSort(arr, len);
								offset = BinarySearch(arr, len, temp->RecordID);
								if (offset==-1) printf("The item isn't exsist\n");
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
						else if (ALT_Lev3 == 2) {
							if (*cnt2 == 0) printf("There is no information\n");
							else {
								char* input = (char*)malloc(sizeof(char) * 9);
								printf("Please input the book name you are to inquire\n");
								scanf("%s", input);
								PrintInquireResult(arr, arr_bookname, cnt1, input, next, cnt_temp, index_len, hit, ini, len);
							}
						}
						else if (ALT_Lev3 == 3) {
							if (*cnt2 == 0) printf("There is no information\n");
							else {
								ini = 0;
								char* input = (char*)malloc(sizeof(char) * 9);
								printf("Please input the author name you are to inquire\n");
								scanf("%s", input);
								PrintInquireResult(arr, arr_authorname, cnt2, input, next, cnt_temp, index_len, hit, ini, len);
							}
						}
						else if (ALT_Lev3 == 4) {
							if (*cnt3 == 0) printf("There is no information\n");
							else {
								ini = 0;
								char* input = (char*)malloc(sizeof(char) * 9);
								printf("Please input the press you are to inquire\n");
								scanf("%s", input);
								PrintInquireResult(arr, arr_press, cnt3, input, next, cnt_temp, index_len, hit, ini, len);
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
			while (ALT_Lev2 != 3) {
				printf("***************************\n\t1.LentOutManagement\n\t2.ReturnManagement\n\t3.BackToPrevious\n*******************************");
				scanf("%d", &ALT_Lev2);
				if (ALT_Lev2 == 1){
					LOAR* temp = (LOAR*)malloc(sizeof(LOAR));
					printf("Plase input the readerID of the people who borrow the book\n");
					scanf("%d",&temp->uid);
					READER* CUR = RINF;
					while (CUR&&CUR->UID!=temp->uid) {
						CUR = CUR->NEXT;
					}
					if (CUR == NULL) {
						printf("Illegal ReaderID\n");
						continue;
					}
					else {
						if (CUR->AvailableBook == 0) {
							printf("Sorry.For this reader,he couldn't borrow book beacause his avaliable book is 0\n");
							continue;
						}
						else {
							printf("Please input the BookID the people want to borrow\n");
							scanf("%d", &temp->bookID);
							BOOK* ptr = arr;
							for (; (ptr - arr) < len; ptr++) if (ptr->BookID == temp->bookID) break;
							if ((ptr - arr) == len) { 
								printf("Illegal BookID\n"); 
								continue;
							}
							else {
								if (ptr->Total != ptr->LendOut) {
									printf("Please input the time of lending out\n");
									printf("YY/MM/DD\n");
									scanf("%s", temp->lendout_date);
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
				else if (ALT_Lev2 == 2){
					LOAR* temp = (LOAR*)malloc(sizeof(LOAR));
					printf("Plase input the readerID of the people who return the book\n");
					scanf("%d", &temp->uid);
					READER* CUR = (READER*)malloc(sizeof(READER));
					CUR = RINF;
					while (CUR && CUR->UID != temp->uid) {
						CUR = CUR->NEXT;
					}
					if (CUR == NULL) {
						printf("Illegal ReaderID\n");
						continue;
					}
					else {
						printf("Please input the BookID the people want to return\n");
						scanf("%d", &temp->bookID);
						LOAR* CUR2 = (LOAR*)malloc(sizeof(LOAR));
						CUR2 = LRINF;
						while (CUR2 && CUR2->bookID != temp->bookID) {
							CUR2 = CUR2->next;
						}
						if (CUR2 == NULL) {
							printf("Illegal BookID in the lend out and return list\n");
							continue;
						}
						else {
								BOOK* ptr = arr;
								for (; (ptr - arr) < len; ptr++) if (ptr->BookID == temp->bookID) break;
								if ((ptr - arr) == len) {
									printf("Illegal BookID in main book list\n");
									continue;
								}
								else {
										printf("Please input the time of returning out\n");
										printf("YY/MM/DD\n");
										scanf("%s", temp->return_date);
										CUR->AvailableBook = CUR->AvailableBook + 1;
										ptr->LendOut = ptr->LendOut - 1;
										strcpy(CUR2->return_date, temp->return_date);
										printf("Any remarks?\n");
										printf("1.Yes\n2.No\n");
										scanf("%d", &temp->uid);
										if (temp->uid == 1) {
											printf("Please input your remarks\n");
											scanf("%s", temp->remarks);
											strcpy(CUR2->remarks, temp->remarks);
										}
										free(temp);
									}
							}
						}
					}
				else if (ALT_Lev2 == 3);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}
		else if (ALT_Lev1 == 5) {/* FILE* FPMB, FILE* FPPI, FILE* FPBNI, FILE* FPBANI*/
			
		USER* CURU = (USER*)malloc(sizeof(USER));
		CURU = UINF->NEXT;
		while (CURU != NULL) {
			fwrite(CURU, sizeof(USER), 1, FPU);
			CURU= CURU->NEXT;
		}
		USER* PREU = (USER*)malloc(sizeof(USER));
		while (CURU != NULL) {
			PREU = CURU;
			CURU = CURU->NEXT;
			free(PREU);
		}
		fclose(FPU);
		READER* CURR = (READER*)malloc(sizeof(READER));
		CURR = RINF->NEXT;
		while (CURR != NULL) {
			fwrite(CURR, sizeof(READER), 1, FPR);
			CURR = CURR->NEXT;
		}
		READER* PRER = (READER*)malloc(sizeof(READER));
		while (CURR != NULL) {
			PRER = CURR;
			CURR = CURR->NEXT;
			free(PRER);
		}
		LOAR* CURLR = (LOAR*)malloc(sizeof(LOAR));
		CURLR = LRINF->next;
		while (CURLR != NULL) {
			fwrite(CURLR, sizeof(LOAR), 1, FPLR);
			CURLR = CURLR->next;
		}
		LOAR* PRELR = (LOAR*)malloc(sizeof(LOAR));
		while (CURLR != NULL) {
			PRELR = CURLR;
			CURLR = CURLR->next;
			free(PRELR);
		}
		fclose(FPLR);
		if(arr!=NULL)fwrite(arr,sizeof(BOOK),len,FPMB);
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
		else printf("Illegal Input\nPlease input your choice again\n");
	}
}