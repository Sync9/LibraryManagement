#include"Header.h"
MBI* creatMainBookIndex(BOOK* arr, int* arrlen) {
	MBI* index = (MBI*)malloc(sizeof(MBI)**arrlen);
	if (index == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	for (int i = 0; i < *arrlen; i++) {
		index[i].bookID = arr[i].bookID;
		index[i].recordID = arr[i].recordID;
	}
	return index;
}