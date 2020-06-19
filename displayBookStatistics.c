#include"Header.h"
void displayBookStatistics(BOOK* arr, int* arrlen) {
	if (arr == NULL) printf("There is no information\n");
	else {
		printf("%20s%20s%20s%9s%9s%9s%9s\n","Bookname","Authorname","Pressname","BookID","RecordID","LendOut","Total");
		for (int i = 0; i < *arrlen; i++) {
			controlFormat();
			printf("%20s%20s%20s%9d%9d%9d%9d\n", (arr + i)->bookname, (arr + i)->authorname, (arr + i)->press, (arr + i)->bookID, (arr + i)->recordID, (arr + i)->lendout, (arr + i)->total);
		}
	}
}