#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Config.h"
/***********************Data Construct*****************************/
typedef struct USER {
	char name[9];
	char passwd[9];
	int UL;
	struct USER* NEXT;
}USER;
typedef struct READER {
	char username[9];
	char readername[9];
	char workplace[15];
	char phonenumber[12];
	int availablebook;
	int unavailablebook;
	struct READER* NEXT;
}READER;
typedef struct BOOK {
	int recordID;
	int bookID;
	char bookname[20];
	char authorname[20];
	char press[20];
	int total;
	int lendout;
	int bookname_ptr;
	int authorname_ptr;
	int pressname_ptr;
}BOOK;
typedef struct INDEX {
	char str[20];
	int head;
	int len;
}INDEX;
typedef struct LOAR {
	char username[9];
	int bookID;
	char lendout_date[11];
	char return_date[11];
	char remarks[12];
	struct LOAR* next;
}LOAR;
typedef struct MBI {
	int recordID;
	int bookID;
}MBI;
/**********************Read and Write File****************************/
USER* readUserInfoFromFile(char* path); 
void writeUserInfotoFile(char* path, USER* head);
READER* readReaderInfoFromFile(char* path);
void writeReaderInfotoFile(char* path, READER* head);
BOOK* readMainBookInfoFromFile(int* arrlen, char* path);
void writeMainBookInfoToFile(char* path, BOOK* arr, int* arrlen);
MBI* readMainBookIndexFromFile(int* arrlen, char* path);
void writeMainBookIndexToFile(char* path, MBI* arr, int* arrlen);
INDEX* readIndexFromFile(int* arrlen, char* path);
void writeIndexToFile(char* path, INDEX* arr, int* arrlen);
LOAR* readLendOutAndReturnInfoFromFile(char* path);
void writeLendOutAndReturnInfotoFile(char* path, LOAR* head);
/*************************Login***************************************/
int SignInAuthorize(USER* head, USER* signin,USER* root);
int signIn(USER* head,USER* signin,USER* root);
void getPasswd(char* passwd, int len_passwd);
/**************************DifferentRoles*****************************/
void SystemAdministrator(int ALT_Lev1, int ALT_Lev2, USER* root, USER* sign_in_info, USER* user_info, BOOK* main_book_info, int* len_main_book_info, INDEX* author_name_index, int* len_author_name_index, INDEX* book_name_index, int* len_book_name_index, INDEX* press_name_index, int* len_press_name_index, MBI* main_book_index, int* len_main_book_index, char* user_info_file_path, char* main_book_info_file_path, char* book_name_index_file_path, char* author_name_index_file_path, char* press_name_index_file_path, char* main_book_index_file_path);
void LibraryAdministrator(int ALT_Lev1, int ALT_Lev2, USER* sign_in_info, USER* user_info, BOOK* main_book_info, int* len_main_book_info, INDEX* author_name_index, int* len_author_name_index, INDEX* book_name_index, int* len_book_name_index, INDEX* press_name_index, int* len_press_name_index, MBI* main_book_index, int* len_main_book_index, READER* reader_info, LOAR* LOAR_info, char* user_info_file_path, char* main_book_info_file_path, char* book_name_index_file_path, char* author_name_index_file_path, char* press_name_index_file_path, char* main_book_index_file_path, char* reader_info_file_path, char* lend_out_and_return_info_file_path);
void Reader(int ALT_Lev1, int ALT_Lev2, USER* sign_in_info, USER* user_info, BOOK* main_book_info, int* len_main_book_info, INDEX* author_name_index, int* len_author_name_index, INDEX* book_name_index, int* len_book_name_index, INDEX* press_name_index, int* len_press_name_index, MBI* main_book_index, int* len_main_book_index, char* user_info_file_path, char* main_book_info_file_path, char* book_name_index_file_path, char* author_name_index_file_path, char* press_name_index_file_path, char* main_book_index_file_path);
/**************************UserManagement*****************************/
USER* inputUserInfo(USER* head, USER* infonode);
USER* modifyPassword(USER* head, USER* infonode,USER* root);
void modifyUserInfo(USER* head, USER* infonode);
void displayUserInfo(USER* head);
void deleteUserInfo(USER* head, USER* infonode);
/*************************ReaderManagement****************************/
READER* inputReaderInfo(READER* head, READER* infonode);
void modifyReaderInfo(READER* head, READER* infonode);
READER* deleteReaderInfo(READER* head, READER* infonode);
void inquireReaderInfo(READER* head, READER* infonode);
void displayReaderInfo(READER* head);
/************************BookManagement*******************************/
BOOK* inputMainBookInfo(BOOK* arr, int* arrlen, BOOK* info);
void modifyMainBookInfo(BOOK* arr, int* arrlen, BOOK* info);
void inquireByBookID(MBI* index_mainbook, int* indexlen, int bookID, char* path);
void inquireByIndex(BOOK* arr_mainbookinfo, int* arrlen_mainbookinfo, INDEX* index, int* indexlen, BOOK* info, int mode); 
void displayBookStatistics(BOOK* arr, int* arrlen);
/************************Tools****************************************/
void InsertionSort(BOOK* arr, int len);
int getBlockNumber(FILE* FP, int block_size); 
int BinarySearch(BOOK* arr, int len, int key);
BOOK* BinarySearchForFile(int recordID, char* path);
void controlFormat();
void Astrisk();
void Center();
void creatFile(char* path);
/************************Index*****************************************/
INDEX* creatIndex(BOOK* arr_mainbookinfo, int* arrlen_mainbookinfo, INDEX* index, int* indexlen, int mode); 
MBI* creatMainBookIndex(BOOK* arr, int* arrlen);
void creatMainBookInfoPointer(BOOK* arr_mainbookinfo, int* arrlen_mainbookinfo);
