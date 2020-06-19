#include"Header.h"
void modifyMainBookInfo(BOOK* arr,int* arrlen,BOOK* info) {
	int offset=BinarySearch(arr, *arrlen, info->bookID);
	arr[offset].bookID = info->bookID;
	arr[offset].recordID = info->recordID;
	arr[offset].total = info->total;
	arr[offset].lendout = info->lendout;
	arr[*arrlen].bookname_ptr = 0;
	arr[*arrlen].authorname_ptr = 0;
	arr[*arrlen].pressname_ptr = 0;
	strcpy(arr[*arrlen].bookname, info->bookname);
	strcpy(arr[*arrlen].authorname, info->authorname);
	strcpy(arr[*arrlen].press, info->press);
}