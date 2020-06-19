#include"Header.h"
void inquireByBookID(MBI* index_mainbook, int* indexlen, int bookID, char* path) {
	int recordID = 0;
	for (int i = 0; i < *indexlen; i++) {
		if (index_mainbook[i].bookID == bookID) {
			recordID = index_mainbook[i].bookID;
			break;
		}
	}
	BOOK* res = NULL;
	res = BinarySearchForFile(recordID, path);
	if (res == NULL) printf("The book is not exist\n");
	else {
		printf("%20s%20s%20s%3s%3s%3s%3s\n", "Bookname", "Authorname", "Pressname", "BookID", "RecordID", "LendOut", "Total");
		controlFormat();
		printf("%20s%20s%20s%3d%3d%3d%3d\n", res->bookname, res->authorname, res->press, res->bookID, res->recordID, res->lendout, res->total);
	}
}