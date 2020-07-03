
#include"Header.h"
INDEX* creatIndex(BOOK* arr_mainbookinfo, int* arrlen_mainbookinfo, INDEX* index, int* indexlen, int mode) {
	INDEX* temp = (INDEX*)malloc(sizeof(INDEX) * *arrlen_mainbookinfo);
	*indexlen = 0;
	for (int i = 0; i < *arrlen_mainbookinfo; i++) {
		if (arr_mainbookinfo[i].bookname_ptr == 0 && mode == 1) {
			strcpy((temp + *indexlen)->str, arr_mainbookinfo[i].bookname);
			(*indexlen)++;
		}
		else if (arr_mainbookinfo[i].authorname_ptr == 0 && mode == 2) {
			strcpy((temp + *indexlen)->str, arr_mainbookinfo[i].authorname);
			(*indexlen)++;
		}
		else if (arr_mainbookinfo[i].pressname_ptr == 0 && mode == 3) {
			strcpy((temp + *indexlen)->str, arr_mainbookinfo[i].press);
			(*indexlen)++;
		}
	}
	INDEX* finalindex = (INDEX*)malloc(sizeof(INDEX) * *indexlen);
	for (int i = 0; i < (*indexlen); i++) {
		strcpy(finalindex[i].str, temp[i].str);
		finalindex[i].len = 0;
		finalindex[i].head = 0;
	}
	free(temp);
	for (int i = *arrlen_mainbookinfo - 1; i >= 0; i--) {
		for (int j = 0; j < (*indexlen); j++) {
			if (strcmp(finalindex[j].str, arr_mainbookinfo[i].bookname) == 0 && mode == 1 && finalindex[j].head == 0) finalindex[j].head = arr_mainbookinfo[i].recordID;
			else if (strcmp(finalindex[j].str, arr_mainbookinfo[i].authorname) == 0 && mode == 2 && finalindex[j].head == 0) finalindex[j].head = arr_mainbookinfo[i].recordID;
			else if (strcmp(finalindex[j].str, arr_mainbookinfo[i].press) == 0 && mode == 3 && finalindex[j].head == 0) finalindex[j].head = arr_mainbookinfo[i].recordID;
			if (strcmp(finalindex[j].str, arr_mainbookinfo[i].bookname) == 0 && mode == 1) finalindex[j].len++;
			else if (strcmp(finalindex[j].str, arr_mainbookinfo[i].authorname) == 0 && mode == 2) finalindex[j].len++;
			else if (strcmp(finalindex[j].str, arr_mainbookinfo[i].press) == 0 && mode == 3) finalindex[j].len++;
		}
	}
	return finalindex;
}
