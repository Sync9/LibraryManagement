#include"Header.h"
int main()
{
	char user_info_file_path[] = { PATHU };
	char reader_info_file_path[] = { PATHR };
	char main_book_info_file_path[] = { PATHMB };
	char main_book_index_file_path[] = { PATHMBI };
	char book_name_index_file_path[] = { PATHBNI };
	char author_name_index_file_path[] = { PATHANI };
	char press_name_index_file_path[] = { PATHPI };
	char lend_out_and_return_info_file_path[] = { PATHLR };
	char root_info_path[] = { PATHRI };
	/************************************************************/
	FILE* root_info_fp = fopen(root_info_path, "rb");
	USER* root = malloc(sizeof(USER));
	if (root_info_fp == NULL) {
		Center();
		controlFormat();
		Astrisk();
		controlFormat();
		printf("There is no user in the system\n");
		controlFormat();
		printf("I will help you become the first system administrator\n");
		root->UL = 2;
		controlFormat();
		printf("You username is root\n");
		strcpy(root->name, "root");
		controlFormat();
		printf("Now please set password for your root account\n");
		controlFormat();
		Astrisk();
		controlFormat();
		scanf("%9s", root->passwd);
		system("reset");
	}
	else {
		fread(root, sizeof(USER), 1, root_info_fp);
		fclose(root_info_fp);
	}
	/************************************************************/
	BOOK* main_book_info = NULL;
	int* len_main_book_info = (int*)malloc(sizeof(int));
	if (root_info_fp != NULL)main_book_info = readMainBookInfoFromFile(len_main_book_info, main_book_info_file_path);
	else *len_main_book_info = 0;
	/************************************************************/
	MBI* main_book_index = NULL;
	int* len_main_book_index = (int*)malloc(sizeof(int));
	if (root_info_fp != NULL)main_book_index = readMainBookIndexFromFile(len_main_book_index, main_book_index_file_path);
	else *len_main_book_index = 0;
	/************************************************************/
	INDEX* book_name_index = NULL;
	int* len_book_name_index = (int*)malloc(sizeof(int));
	if (root_info_fp != NULL)book_name_index = readIndexFromFile(len_book_name_index, book_name_index_file_path);
	else *len_book_name_index = 0;
	/*************************************************************/
	INDEX* author_name_index = NULL;
	int* len_author_name_index = (int*)malloc(sizeof(int));
	if (root_info_fp != NULL)author_name_index = readIndexFromFile(len_author_name_index, author_name_index_file_path);
	else *len_author_name_index = 0;
	/************************************************************/
	INDEX* press_name_index = NULL;
	int* len_press_name_index = (int*)malloc(sizeof(int));
	if (root_info_fp != NULL)press_name_index = readIndexFromFile(len_press_name_index, press_name_index_file_path);
	else *len_press_name_index = 0;
	/************************************************************/
	USER* user_info = (USER*)malloc(sizeof(USER));
	if (root_info_fp != NULL)user_info = readUserInfoFromFile(user_info_file_path);
	else user_info = NULL;
	/************************************************************/
	USER* sign_in_info = (USER*)malloc(sizeof(USER));
	if (signIn(user_info, sign_in_info, root) != 0) {
		int ALT_Lev1 = 0;
		int ALT_Lev2 = 0;
		if (sign_in_info->UL == 3) {
			READER* reader_info = NULL;
			creatFile(reader_info_file_path);
			reader_info = readReaderInfoFromFile(reader_info_file_path);
			LOAR* LOAR_info = NULL;
			creatFile(lend_out_and_return_info_file_path);
			LOAR_info = readLendOutAndReturnInfoFromFile(lend_out_and_return_info_file_path);
			LibraryAdministrator(ALT_Lev1, ALT_Lev2, sign_in_info, user_info, main_book_info, len_main_book_info, author_name_index, len_author_name_index, book_name_index, len_book_name_index, press_name_index, len_press_name_index, main_book_index, len_main_book_index,reader_info, LOAR_info,user_info_file_path,main_book_info_file_path,book_name_index_file_path,author_name_index_file_path,press_name_index_file_path,main_book_index_file_path,reader_info_file_path,lend_out_and_return_info_file_path);
		}
		else if (sign_in_info->UL == 2)	SystemAdministrator(ALT_Lev1, ALT_Lev2,root,sign_in_info, user_info, main_book_info, len_main_book_info, author_name_index, len_author_name_index, book_name_index, len_book_name_index, press_name_index, len_press_name_index, main_book_index, len_main_book_index, user_info_file_path,main_book_info_file_path,book_name_index_file_path,author_name_index_file_path,press_name_index_file_path,main_book_index_file_path);
		else if (sign_in_info->UL == 1) Reader(ALT_Lev1, ALT_Lev2, sign_in_info,user_info,main_book_info,len_main_book_info,author_name_index,len_author_name_index,book_name_index,len_main_book_index,press_name_index,len_press_name_index,main_book_index,len_main_book_index,user_info_file_path,main_book_info_file_path,book_name_index_file_path,author_name_index_file_path,press_name_index_file_path,main_book_index_file_path);
	}
	/*else {
		writeUserInfotoFile(user_info_file_path, user_info);
		writeMainBookInfoToFile(main_book_info_file_path, main_book_info, len_main_book_info);
		writeMainBookIndexToFile(main_book_index_file_path, main_book_index, len_main_book_index);
		writeIndexToFile(book_name_index_file_path, book_name_index, len_book_name_index);
		writeIndexToFile(author_name_index_file_path, author_name_index, len_author_name_index);
		writeIndexToFile(press_name_index_file_path, press_name_index, len_press_name_index);
	}*/
	root_info_fp = fopen(root_info_path, "wb");
	if (root != NULL) {
		fwrite(root, sizeof(USER), 1, root_info_fp);
		fclose(root_info_fp);
	}
}
