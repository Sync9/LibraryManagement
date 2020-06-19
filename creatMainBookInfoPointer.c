#include"Header.h"
void creatMainBookInfoPointer(BOOK* arr_mainbookinfo,int* arrlen_mainbookinfo) {
	int memo_bookname = 0;
	int memo_authorname = 0;
	int memo_pressname = 0;
	for (int i = 0; i < *arrlen_mainbookinfo; i++) {
		(arr_mainbookinfo + i)->bookname_ptr = 0;
		(arr_mainbookinfo + i)->authorname_ptr = 0;
		(arr_mainbookinfo + i)->pressname_ptr = 0;
	}
	for (int i = 0; i < *arrlen_mainbookinfo; i++) {
		memo_bookname = (arr_mainbookinfo + i)->recordID;
		memo_authorname = (arr_mainbookinfo + i)->recordID;
		memo_pressname = (arr_mainbookinfo + i)->recordID;
		for (int j = i + 1; j < *arrlen_mainbookinfo; j++) {
			if (strcmp(arr_mainbookinfo[i].bookname, arr_mainbookinfo[j].bookname) == 0 && (arr_mainbookinfo + j)->bookname_ptr == 0) {
				arr_mainbookinfo[j].bookname_ptr = memo_bookname;
				memo_bookname = (arr_mainbookinfo + j)->recordID;
			}
			if (strcmp(arr_mainbookinfo[i].authorname, arr_mainbookinfo[j].authorname) == 0 && (arr_mainbookinfo + j)->authorname_ptr == 0) {
				arr_mainbookinfo[j].authorname_ptr = memo_authorname;
				memo_authorname = (arr_mainbookinfo + j)->recordID;
			}
			if (strcmp(arr_mainbookinfo[i].press, arr_mainbookinfo[j].press) == 0 && (arr_mainbookinfo + j)->pressname_ptr == 0) {
				arr_mainbookinfo[j].pressname_ptr = memo_pressname;
				memo_pressname = (arr_mainbookinfo + j)->recordID;
			}
		}
	}
}