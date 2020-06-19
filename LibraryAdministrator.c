#include"Header.h"
void LibraryAdministrator(int ALT_Lev1, int ALT_Lev2, USER* sign_in_info, USER* user_info, BOOK* main_book_info, int* len_main_book_info, INDEX* author_name_index, int* len_author_name_index, INDEX* book_name_index, int* len_book_name_index, INDEX* press_name_index, int* len_press_name_index, MBI* main_book_index, int* len_main_book_index,READER* reader_info, LOAR* LOAR_info, char* user_info_file_path, char* main_book_info_file_path, char* book_name_index_file_path, char* author_name_index_file_path, char* press_name_index_file_path, char* main_book_index_file_path,char* reader_info_file_path,char* lend_out_and_return_info_file_path) {
	while (ALT_Lev1 != 5) {
		ALT_Lev1 = 0;
		ALT_Lev2 = 0;
		int time = 1;
		printf("Sign in as UserID = %s  UserLevel = %d", sign_in_info->name, sign_in_info->UL);
		printf("\n\n\n\n\n");
		controlFormat();
		Astrisk();
		controlFormat();
		printf("1----UserManagement\n");
		controlFormat();
		printf("2----ReaderManagement\n");
		controlFormat();
		printf("3----BookManagement\n");
		controlFormat();
		printf("4----BookCirculationManagement\n");
		controlFormat();
		printf("5----Exit\n");
		controlFormat();
		Astrisk();
		controlFormat();
		scanf("%d", &ALT_Lev1);
		system("reset");
		if (ALT_Lev1 == 1) {
			while (ALT_Lev2 != 6) {
				Center();
				controlFormat();
				Astrisk();
				controlFormat();
				printf("1----InputUserInformation\n");
				controlFormat();
				printf("2----ModifyUserInformation\n");
				controlFormat();
				printf("3----DeleteUserInformation\n");
				controlFormat();
				printf("4----DisplayUserInformation\n");
				controlFormat();
				printf("5----ModifyUserPassword\n");
				controlFormat();
				printf("6----BackToPrevious\n");
				controlFormat();
				Astrisk();
				controlFormat();
				scanf("%d", &ALT_Lev2);
				system("reset");
				if (ALT_Lev2 == 5) {
					USER* info = (USER*)malloc(sizeof(USER));
					if (info == NULL) {
						printf("Fail to apply memory\n");
						exit(1);
					}
					Center();
					controlFormat();
					Astrisk();
					strcpy(info->name, sign_in_info->name);
					controlFormat();
					printf("Please input the Password\n");
					controlFormat();
					printf("No more than 9 letter or number\n");
					controlFormat();
					Astrisk();
					controlFormat();
					scanf("%9s", info->passwd);
					system("reset");
					info->UL=sign_in_info->UL;
					modifyUserInfo(user_info, info);
					system("reset");
					free(info);
				}
				else if (ALT_Lev2 == 1 || ALT_Lev2 == 3 || ALT_Lev2 == 4 || ALT_Lev2 == 2)  printf("Sorry,it's seems that you have no access to the feature:(\n");
				else if (ALT_Lev2 == 6);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}
		else if (ALT_Lev1 == 2) {
			while (ALT_Lev2 != 6) {
				Center();
				controlFormat();
				Astrisk();
				controlFormat();
				printf("1----InputReaderInformation\n");
				controlFormat();
				printf("2----ModifyReaderInformation\n");
				controlFormat();
				printf("3----DeleteReaderInformation\n");
				controlFormat();
				printf("4----FindReaderInformation\n");
				controlFormat();
				printf("5----DisplayReaderInformation\n");
				controlFormat();
				printf("6----BackToPrevious\n");
				controlFormat();
				Astrisk();
				controlFormat();
				scanf("%d", &ALT_Lev2);
				system("reset");
				READER* info = (READER*)malloc(sizeof(READER));
				if (info == NULL) {
					printf("Fail to apply for memory\n");
					exit(1);
				}
				else {
					if (ALT_Lev2 == 1) {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the username you wanna input\n");
						controlFormat();
						printf("No more than 9 letter or number\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%9s", info->username);
						system("reset");
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the reader name\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%9s", info->readername);
						system("reset");
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the WorkPlace\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%15s", info->workplace);
						system("reset");
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the PhoneNumber\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%12s", info->phonenumber);
						system("reset");
						do {
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the AvailableBook\n");
							controlFormat();
							printf("The number of available book couldn't be negative\n");
							controlFormat();
							Astrisk();
							controlFormat();
							scanf("%d", &info->availablebook);
							system("reset");
						} while (info->availablebook < 0);
						do {
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the UnavailableBook\n");
							controlFormat();
							printf("The number of unavailable book couldn't be negative\n");
							controlFormat();
							Astrisk();
							controlFormat();
							scanf("%d", &info->unavailablebook);
							system("reset");
						} while (info->unavailablebook < 0);
						reader_info=inputReaderInfo(reader_info, info);
					}
					else if (ALT_Lev2 == 2) {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the username you wanna modify\n");
						controlFormat();
						printf("No more than 9 letter or number\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%9s", info->username);
						system("reset");
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the reader name\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%9s", info->readername);
						system("reset");
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the WorkPlace\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%15s", info->workplace);
						system("reset");
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the PhoneNumber\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%12s", info->phonenumber);
						system("reset");
						do {
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the AvailableBook\n");
							controlFormat();
							printf("The number of available book couldn't be negative\n");
							controlFormat();
							Astrisk();
							controlFormat();
							scanf("%d", &info->availablebook);
							system("reset")
						} while (info->availablebook < 0);
						do {
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the UnavailableBook\n");
							controlFormat();
							printf("The number of unavailable book couldn't be negative\n");
							controlFormat();
							Astrisk();
							controlFormat();
							scanf("%d", &info->unavailablebook);
							system("reset")
						} while (info->unavailablebook < 0);
						modifyReaderInfo(reader_info, info);
					}
					else if (ALT_Lev2 == 3) {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Which reader are you going to Delete?\n");
						controlFormat();
						printf("Please input his/her User name\n");
						controlFormat();
						printf("No more than 9 letter or number\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%9s", info->username);
						system("reset")
						deleteReaderInfo(reader_info, info);
					}
					else if (ALT_Lev2 == 4) {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Which reader are you going to find?\n");
						controlFormat();
						printf("Please input his/her Reader name\n");
						controlFormat();
						printf("No more than 9 letter or number\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%9s", info->readername);
						system("reset")
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						inquireReaderInfo(reader_info, info);
						controlFormat();
						Astrisk();
					}
					else if (ALT_Lev2 == 5) {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						displayReaderInfo(reader_info);
						controlFormat();
						Astrisk();
					}
					else if (ALT_Lev2 == 6);
					else printf("Illegal Input\nPlease input your choice again\n");
					free(info);
				}
			}
		}
		else if (ALT_Lev1 == 3) {
			while (ALT_Lev2 != 5) {
				do {
					Center();
					controlFormat();
					Astrisk();
					controlFormat();
					printf("1----InputBookInformation\n");
					controlFormat();
					printf("2----ModifyBookInformation\n");
					controlFormat();
					printf("3----InquireBookInformation\n");
					controlFormat();
					printf("4----TotalStatistics\n");
					controlFormat();
					printf("5----BackToPrevious\n");
					controlFormat();
					Astrisk();
					controlFormat();
					scanf("%d", &ALT_Lev2);
					system("reset")
				} while (ALT_Lev2 < 1 && ALT_Lev2>5);
				if (ALT_Lev2 == 1) {
					BOOK* info = (BOOK*)malloc(sizeof(BOOK));
					do {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the RecordID\n");
						controlFormat();
						printf("RecordID couldn't smaller than 1 \n");
						controlFormat(); 
						Astrisk();
						controlFormat();
						scanf("%d", &info->recordID);
						system("reset")
					} while (info->recordID < 1);
					do {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the BookID\n");
						controlFormat();
						printf("BookID couldn't smaller than 1 \n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%d", &info->bookID);
						system("reset")

					} while (info->bookID < 1);
					Center();
					controlFormat();
					Astrisk();
					controlFormat();
					printf("Please input the book name\n");
					controlFormat();
					Astrisk();
					controlFormat();
					scanf("%20s", info->bookname);
					system("reset")
					Center();
					controlFormat();
					Astrisk();
					controlFormat();
					printf("Please input the author name\n");
					controlFormat();
					Astrisk();
					controlFormat();
					scanf("%20s", info->authorname);
					system("reset")
					Center();
					controlFormat();
					Astrisk();
					controlFormat();
					printf("Please input the press name\n");
					controlFormat();
					Astrisk();
					controlFormat();
					scanf("%20s", info->press);
					system("reset")
					do {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the number of the book lent out\n");
						controlFormat();
						printf("The number of the book lent out couldn't be negative\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%d", &info->lendout);
						system("reset")
					} while (info->lendout < 0);
					do {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Please input the sum of the book\n");
						controlFormat();
						printf("The sum of the book lent out couldn't be negative\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%d", &info->total);
						system("reset")
					} while (info->total < 0);
					main_book_info=inputMainBookInfo(main_book_info,len_main_book_info,info);
					creatMainBookInfoPointer(main_book_info, len_main_book_info);
					book_name_index=creatIndex(main_book_info, len_main_book_info, book_name_index, len_book_name_index, 1);
					author_name_index = creatIndex(main_book_info, len_main_book_info, author_name_index, len_author_name_index, 2);
					press_name_index = creatIndex(main_book_info, len_main_book_info, press_name_index, len_press_name_index, 3);
					free(info);
				}
				else if (ALT_Lev2 == 2) {
					if (main_book_info == NULL) printf("There is no information\n");
					else {
						BOOK* info = (BOOK*)malloc(sizeof(BOOK));
						if (info == NULL) {
							printf("Fail to apply for memory\n");
							exit(1);
						}
						else {
							do {
								Center();
								controlFormat();
								Astrisk();
								controlFormat();
								printf("Please input the number of the book lent out\n");
								controlFormat();
								printf("The number of the book lent out couldn't be negative\n");
								controlFormat();
								Astrisk();
								controlFormat();
								scanf("%d", &info->lendout);
								system("reset")
							} while (info->lendout < 0);
							do {
								controlFormat();
								Astrisk();
								controlFormat();
								printf("Please input the sum of the book\n");
								controlFormat();
								printf("The sum of the book lent out couldn't be negative\n");
								controlFormat();
								Astrisk();
								controlFormat();
								scanf("%d", &info->total);
								system("reset")
							} while (info->total < 0);
							modifyMainBookInfo(main_book_info, len_main_book_info, info);
							free(info);
						}
					}
				}
				else if (ALT_Lev2 == 3) {
					int ALT_Lev3 = 0;
					while (ALT_Lev3 != 5) {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("1----By BookID\n");
						controlFormat();
						printf("2----By BookName\n");
						controlFormat();
						printf("3----By AuthorName\n");
						controlFormat();
						printf("4----By Press\n");
						controlFormat();
						printf("5----BackToPrevious\n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%d", &ALT_Lev3);
						system("reset")
						if (ALT_Lev3 == 1) {
							int bookID = 0;
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the bookID you are going to inquire\n");
							controlFormat();
							Astrisk();
							controlFormat();
							scanf("%d", &bookID);
							system("reset")
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							inquireByBookID(main_book_index, len_main_book_index, bookID, main_book_info_file_path);
							controlFormat();
							Astrisk();
						}
						else if (ALT_Lev3 == 2) {
							BOOK* info = (BOOK*)malloc(sizeof(BOOK));
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the book name you are going to inquire\n");
							controlFormat();
							scanf("%20s", info->bookname);
							system("reset")
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							inquireByIndex(main_book_info, len_main_book_info, book_name_index, len_book_name_index, info, 1);
							controlFormat();
							Astrisk();
							free(info);
						}
						else if (ALT_Lev3 == 3) {
							BOOK* info = (BOOK*)malloc(sizeof(BOOK));
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the author name you are going to inquire\n");
							controlFormat();
							scanf("%20s", info->authorname);
							system("reset")
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							inquireByIndex(main_book_info, len_main_book_info, author_name_index, len_author_name_index, info, 2);
							controlFormat();
							Astrisk();
							free(info);
						}
						else if (ALT_Lev3 == 4) {
							BOOK* info = (BOOK*)malloc(sizeof(BOOK));
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the press name you are going to inquire\n");
							controlFormat();
							scanf("%20s", info->press);
							system("reset")
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							inquireByIndex(main_book_info, len_main_book_info, press_name_index, len_press_name_index, info, 3);
							controlFormat();
							Astrisk();
							free(info);
						}
						else if (ALT_Lev3 == 5);
						else printf("Illegal Input\nPlease input your choice again\n");
					}
				}
				else if (ALT_Lev2 == 4) {
					Center();
					controlFormat();
					Astrisk();
					controlFormat();
					displayBookStatistics(main_book_info, len_main_book_info);
					controlFormat();
					Astrisk();
				}
				else if (ALT_Lev2 == 5);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}
		else if (ALT_Lev1 == 4) {
			while (ALT_Lev2 != 3) {
				Center();
				controlFormat();
				Astrisk();
				controlFormat();
				printf("1----LentOutManagement\n");
				controlFormat();
				printf("2----ReturnManagement\n");
				controlFormat();
				printf("3----BackToPrevious\n");
				controlFormat();
				Astrisk();
				controlFormat();
				scanf("%d", &ALT_Lev2);
				system("reset")
				if (ALT_Lev2 == 1) {
					LOAR* temp = (LOAR*)malloc(sizeof(LOAR));
					if (temp == NULL) {
						printf("Fail to apply for memory\n");
						exit(1);
					}
					else {
						Center();
						controlFormat();
						Astrisk();
						controlFormat();
						printf("Plase input the readerID of the people who borrow the book\n");
						controlFormat();
						printf("RecordID couldn't smaller than 1 \n");
						controlFormat();
						Astrisk();
						controlFormat();
						scanf("%s", &temp->username);
						system("reset")
						READER* CUR = reader_info;
						while (CUR && strcmp(CUR->username,temp->username)!=0) {
							CUR = CUR->NEXT;
						}
						if (CUR == NULL) {
							printf("Illegal ReaderID\n");
							continue;
						}
						else {
							if (CUR->availablebook == 0) {
								printf("Sorry.For this reader,he couldn't borrow book beacause his avaliable book is 0\n");
								continue;
							}
							else {
								do {
									Center();
									controlFormat();
									Astrisk();
									controlFormat();
									printf("Please input the BookID the people want to borrow\n");
									controlFormat();
									printf("BookID couldn't smaller than 1 \n");
									controlFormat();
									Astrisk();
									controlFormat();
									scanf("%d", &temp->bookID);
									system("reset")
								} while (temp->bookID < 1);
								BOOK* ptr = main_book_info;
								for (; (ptr - main_book_info) < *len_main_book_info; ptr++) if (ptr->bookID == temp->bookID) break;
								if ((ptr - main_book_info) == *len_main_book_info) {
									printf("Illegal BookID\n");
									continue;
								}
								else {
									if (ptr->total != ptr->lendout) {
										Center();
										controlFormat();
										Astrisk();
										controlFormat();
										printf("Please input the time of lending out\n");
										controlFormat();
										printf("YY/MM/DD\n");
										controlFormat();
										Astrisk();
										controlFormat();
										scanf("%11s", temp->lendout_date);
										system("reset")
										CUR->availablebook = CUR->availablebook - 1;
										ptr->lendout = ptr->lendout + 1;
										LOAR* LOAR_lo_ptr = (LOAR*)malloc(sizeof(LOAR));
										LOAR* LOAR_hi_ptr = (LOAR*)malloc(sizeof(LOAR));
										LOAR* LOAR_newnode = (LOAR*)malloc(sizeof(LOAR));
										LOAR_newnode->next = NULL;
										LOAR_newnode->bookID = temp->bookID;
										strcpy(LOAR_newnode->lendout_date, temp->lendout_date);
										strcpy(LOAR_newnode->return_date, temp->return_date);
										strcpy(LOAR_newnode->remarks, temp->remarks);
										strcpy(LOAR_newnode->username, temp->username);
										LOAR_lo_ptr = LOAR_info;
										LOAR_hi_ptr = LOAR_info;
										while (LOAR_hi_ptr) {
											LOAR_lo_ptr = LOAR_hi_ptr;
											LOAR_hi_ptr = LOAR_hi_ptr->next;
										}
										if (LOAR_lo_ptr == LOAR_hi_ptr) LOAR_info->next = LOAR_newnode;
										else LOAR_lo_ptr->next = LOAR_newnode;
										LOAR_newnode->next = LOAR_hi_ptr;
										free(LOAR_hi_ptr);
										while (LOAR_lo_ptr) LOAR_lo_ptr = LOAR_lo_ptr->next;
										free(LOAR_lo_ptr);
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
				else if (ALT_Lev2 == 2) {
					LOAR* temp = (LOAR*)malloc(sizeof(LOAR));
					if (temp == NULL) {
						printf("Fail to apply for memory\n");
						exit(1);
					}
					Center();
					controlFormat();
					Astrisk();
					controlFormat();
					printf("Plase input the reader name of the people who borrow the book\n");
					controlFormat();
					printf("RecordID couldn't smaller than 1 \n");
					controlFormat();
					Astrisk();
					controlFormat();
					scanf("%s", &temp->username);
					system("reset")
					READER* CUR = (READER*)malloc(sizeof(READER));
					CUR = reader_info;
					while (CUR && strcmp(CUR->username, temp->username) != 0) {
						CUR = CUR->NEXT;
					}
					if (CUR == NULL) {
						printf("Illegal ReaderID\n");
						continue;
					}
					else {
						do {
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							printf("Please input the BookID the people want to borrow\n");
							controlFormat();
							printf("BookID couldn't smaller than 1 \n");
							controlFormat();
							Astrisk();
							controlFormat();
							scanf("%d", &temp->bookID);
							system("reset")
						} while (temp->bookID < 1);
						LOAR* CUR2 = (LOAR*)malloc(sizeof(LOAR));
						CUR2 = LOAR_info;
						while (CUR2 && CUR2->bookID != temp->bookID) {
							CUR2 = CUR2->next;
						}
						if (CUR2 == NULL) {
							printf("Illegal BookID in the lend out and return list\n");
							continue;
						}
						else {
							BOOK* ptr = main_book_info;
							for (; (ptr - main_book_info) < *len_main_book_info; ptr++) if (ptr->bookID == temp->bookID) break;
							if ((ptr - main_book_info) == *len_main_book_info) {
								printf("Illegal BookID\n");
								continue;
							}
							else {
								Center();
								controlFormat();
								Astrisk();
								controlFormat();
								printf("Please input the time of returning out\n");
								controlFormat();
								printf("YY/MM/DD\n");
								controlFormat();
								Astrisk();
								controlFormat();
								scanf("%s", temp->return_date);
								system("reset")
								CUR->availablebook = CUR->availablebook + 1;
								ptr->lendout = ptr->lendout - 1;
								strcpy(CUR2->return_date, temp->return_date);
								Center();
								controlFormat();
								Astrisk();
								controlFormat();
								printf("Any remarks?\n");
								controlFormat();
								printf("1.Yes\n2.No\n");
								Center();
								controlFormat();
								Astrisk();
								controlFormat();
								int alt = 0;
								scanf("%d", &alt);
								system("reset")
								if (alt == 1) {
									Center();
									controlFormat();
									Astrisk();
									controlFormat();
									printf("Please input your remarks\n");
									controlFormat();
									Astrisk();
									controlFormat();
									scanf("%12s", temp->remarks);
									system("reset")
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
		else if (ALT_Lev1 == 5) {
			writeUserInfotoFile(user_info_file_path, user_info);
			writeMainBookInfoToFile(main_book_info_file_path, main_book_info, len_main_book_info);
			writeMainBookIndexToFile(main_book_index_file_path, main_book_index, len_main_book_index);
			writeIndexToFile(book_name_index_file_path, book_name_index, len_book_name_index);
			writeIndexToFile(author_name_index_file_path, author_name_index, len_author_name_index);
			writeIndexToFile(press_name_index_file_path, press_name_index, len_press_name_index);
			writeReaderInfotoFile(reader_info_file_path, reader_info);
			writeLendOutAndReturnInfotoFile(lend_out_and_return_info_file_path, LOAR_info);
		}
		else printf("Illegal Input\nPlease input your choice again\n");
	}
}