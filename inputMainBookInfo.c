//--tested
#include"Header.h"
BOOK* inputMainBookInfo(BOOK* arr, int* arrlen, BOOK* info) {
	BOOK* newarr = (BOOK*)malloc(sizeof(BOOK) * (*arrlen + 1));
	if (newarr == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	for (int i = 0; i < *arrlen; i++) {
		newarr[i].bookID = arr[i].bookID;
		newarr[i].recordID = arr[i].recordID;
		newarr[i].total = arr[i].total;
		newarr[i].lendout = arr[i].lendout;
		newarr[i].bookname_ptr = arr[i].bookname_ptr;
		newarr[i].authorname_ptr = arr[i].authorname_ptr;
		newarr[i].pressname_ptr = arr[i].pressname_ptr;
		strcpy(newarr[i].bookname, arr[i].bookname);
		strcpy(newarr[i].authorname, arr[i].authorname);
		strcpy(newarr[i].press, arr[i].press);
	}
	newarr[*arrlen].bookID = info->bookID;
	newarr[*arrlen].recordID = info->recordID;
	newarr[*arrlen].total = info->total;
	newarr[*arrlen].lendout = info->lendout;
	newarr[*arrlen].bookname_ptr = 0;
	newarr[*arrlen].authorname_ptr = 0;
	newarr[*arrlen].pressname_ptr = 0;
	strcpy(newarr[*arrlen].bookname, info->bookname);
	strcpy(newarr[*arrlen].authorname, info->authorname);
	strcpy(newarr[*arrlen].press, info->press);
	free(arr);
	(*arrlen)++;
	if(*arrlen>1)InsertionSort(newarr, *arrlen);
	return newarr;
}
