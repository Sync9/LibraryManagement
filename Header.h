#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Config.h"
typedef struct USER {
	int UID;//UID=UserID
	char Password[9];
	int UL;//UserLevel
	struct USER* NEXT;
}USER;
typedef struct READER {
	int UID;
	char Name[9];
	char WorkPlace[15];
	char PhoneNumber[12];
	int AvailableBook;
	int UnAvailableBook;
	struct READER* NEXT;
}READER;
typedef struct BOOK {
	int RecordID;
	int BookID;
	char BookName[9];
	char AuthorName[9];
	char Press[9];
	int Total;
	int LendOut;
	int bookname_ptr;
	int authorname_ptr;
	int press_ptr;
}BOOK;
typedef struct INDEX {
	char str[9];
	int ini;
	int len;
}INDEX;
typedef struct LOAR {
	int uid;
	int bookID;
	char lendout_date[11];
	char return_date[11];
	char remarks[12];
	struct LOAR* next;
}LOAR;
/*************************/
USER* USERInformationLinkedListCreat(FILE* FP, char* path, USER* Head,USER* firstuser);
READER* READERInformationLinkedListCreat(FILE* FP, char* path, READER* Head);
LOAR* LOARInformationLinkedListCreat(FILE* FP, char* path, LOAR* Head);
/*Login*/
int Login(int counter, USER* UINF, USER* Signin);
int SignInAuthorize(USER* Head, USER* Signin);
/*UserManagement*/
USER* UserManagement_1_UserInformationInput(USER* Head, USER* NewNode);
USER* UserManagement_2_ModifyUserInformation(USER* Head, USER* NewNode);
USER* UserManagement_3_DeleteUserInformation(USER* Head, USER* NewNode);
USER* UserManagement_4_DisplayUserInformation(USER* Head);
USER* UserManagement_5_ModifyUserPassword(USER* Head, USER* NewNode);
/*ReaderManagement*/
READER* ReaderManagement_1_ReaderInformationInput(READER* Head, READER* NewNode);
READER* ReaderManagement_2_ModifyReaderInformation(READER* Head, READER* NewNode);
READER* ReaderManagement_3_DeleteReaderInformation(READER* Head, READER* NewNode);
READER* ReaderManagement_4_inidReaderInformation(READER* Head, READER* NewNode);
READER* ReaderManagement_5_DisplayReaderInformation(READER* Head);
/*BookManagement*/
BOOK* BookManagement_1_BookInformationInput(BOOK* arr, BOOK* bookinfo, int len, int cnt);
void BookManagement_2_BookInformationModify(BOOK* arr, int len, BOOK* info);
INDEX* BookManagement_By(BOOK* arr, int len, INDEX* index, int* cnt, int stat);
void PrintInquireResult(BOOK* arr, INDEX* index, int* cnt2, char* input, int next, int cnt_temp, int index_len, int hit, int ini, int len);
/*DifferentRole*/
void SystemAdministrator(int ALT_Lev1, int ALT_Lev2, USER* UINF, FILE* FP, FILE* FPMB, FILE* FPPI, FILE* FPBNI, FILE* FPBANI, BOOK* arr, int len, INDEX* arr_authorname, INDEX* arr_bookname, INDEX* arr_press);
void LibraryAdministrator(int ALT_Lev1, int ALT_Lev2, USER* UINF, READER* RINF, LOAR* LRINF, FILE* FPU, FILE* FPR, FILE* FPMB, FILE* FPPI, FILE* FPBNI, FILE* FPBANI, FILE* FPLR, BOOK* arr, int len, INDEX* arr_authorname, INDEX* arr_bookname, INDEX* arr_press);
void Reader(int ALT_Lev1, int ALT_Lev2,int UID,USER* UINF,READER* RINF,LOAR* LRINF, FILE* FPU,FILE* FPR,FILE* FPLR,FILE* FPMB, FILE* FPPI, FILE* FPBNI, FILE* FPBANI, BOOK* arr, int len, INDEX* arr_authorname, INDEX* arr_bookname, INDEX* arr_press);
/*Tool*/
void InsertionSort(BOOK* arr, int len);
int BinarySearch(BOOK* arr, int len, int key);
INDEX* RemoveDuplicate(BOOK* arr, int len, int stat, int* cnt);
int GetNumberOfBlock(FILE* FP, int block_size);
INDEX* CreatIndex(BOOK* arr, int len, INDEX* index, int* cnt, int stat);
LOAR* AddNewNode(LOAR* head, LOAR* newnode);
