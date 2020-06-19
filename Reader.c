#include"Header.h"
void Reader(int ALT_Lev1, int ALT_Lev2, USER* sign_in_info, USER* user_info, BOOK* main_book_info, int* len_main_book_info, INDEX* author_name_index, int* len_author_name_index, INDEX* book_name_index, int* len_book_name_index, INDEX* press_name_index, int* len_press_name_index, MBI* main_book_index, int* len_main_book_index, char* user_info_file_path, char* main_book_info_file_path, char* book_name_index_file_path, char* author_name_index_file_path, char* press_name_index_file_path, char* main_book_index_file_path) {
	while (ALT_Lev1 != 5) {
		ALT_Lev1 = 0;
		ALT_Lev2 = 0;
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
		system("cls");
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
				system("cls");
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
					system("cls");
					info->UL = sign_in_info->UL;
					modifyUserInfo(user_info, info);
					system("cls");
					free(info);
				}
				else if (ALT_Lev2 == 1 || ALT_Lev2 == 3 || ALT_Lev2 == 4 || ALT_Lev2 == 2)  printf("Sorry,it's seems that you have no access to the feature:(\n");
				else if (ALT_Lev2 == 6);
				else printf("Illegal Input\nPlease input your choice again\n");
			}
		}
		else if (ALT_Lev1 == 2||ALT_Lev1==4) {
			printf("Sorry,it's seems that you have no access to the feature:(\n");
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
					system("cls");
				} while (ALT_Lev2 < 1 && ALT_Lev2>5);
				if (ALT_Lev2 == 1 || ALT_Lev2 == 2) printf("Sorry,it's seems that you have no access to the feature:(\n");
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
						system("cls");
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
							system("cls");
							Center();
							controlFormat();
							Astrisk();
							controlFormat();
							if (main_book_info == NULL) printf("There is no book info in the system\n");
							else inquireByBookID(main_book_index, len_main_book_index, bookID, main_book_info_file_path);
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
							Astrisk();
							controlFormat();
							scanf("%20s", info->bookname);
							system("cls");
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
							Astrisk();
							controlFormat();
							scanf("%20s", info->authorname);
							system("cls");
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
							Astrisk();
							controlFormat();
							scanf("%20s", info->press);
							system("cls");
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
		else if (ALT_Lev1 == 5) {
			writeUserInfotoFile(user_info_file_path, user_info);
			writeMainBookInfoToFile(main_book_info_file_path, main_book_info, len_main_book_info);
			writeMainBookIndexToFile(main_book_index_file_path, main_book_index, len_main_book_index);
			writeIndexToFile(book_name_index_file_path, book_name_index, len_book_name_index);
			writeIndexToFile(author_name_index_file_path, author_name_index, len_author_name_index);
			writeIndexToFile(press_name_index_file_path, press_name_index, len_press_name_index);
		}
		else printf("Illegal Input\nPlease input your choice again\n");
	}
}