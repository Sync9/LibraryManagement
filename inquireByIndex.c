#include"Header.h"
void inquireByIndex(BOOK* arr_mainbookinfo, int* arrlen_mainbookinfo, INDEX* index, int* indexlen, BOOK* info, int mode) {
	if (index == NULL) { 
		printf("There is no info\n");
	}
	else {
		int offset_index = 0;
		for (; offset_index < *indexlen; offset_index++) {
			if (mode == 1 && strcmp(index[offset_index].str, info->bookname) == 0) break;
			else if (mode == 2 && strcmp(index[offset_index].str, info->authorname) == 0) break;
			else if (mode == 3 && strcmp(index[offset_index].str, info->press) == 0) break;
		}
		int offset_mainbookinfo = 0;
		offset_mainbookinfo = index[offset_index].head;
		printf("%20s%20s%20s%9s%9s%9s%9s\n", "Bookname", "Authorname", "Pressname", "BookID", "RecordID", "LendOut", "Total");
		for (int i = 0; i < index[offset_index].len; i++) {
			offset_mainbookinfo = BinarySearch(arr_mainbookinfo, *arrlen_mainbookinfo, offset_mainbookinfo);
			if (offset_mainbookinfo == -1) break;
			controlFormat();
			printf("%20s%20s%20s%9d%9d%9d%9d\n", arr_mainbookinfo[offset_mainbookinfo].bookname, arr_mainbookinfo[offset_mainbookinfo].authorname, arr_mainbookinfo[offset_mainbookinfo].press, arr_mainbookinfo[offset_mainbookinfo].bookID, arr_mainbookinfo[offset_mainbookinfo].recordID, arr_mainbookinfo[offset_mainbookinfo].lendout, arr_mainbookinfo[offset_mainbookinfo].total);
			if (mode == 1)offset_mainbookinfo = arr_mainbookinfo[offset_mainbookinfo].bookname_ptr;
			else if (mode == 2)offset_mainbookinfo = arr_mainbookinfo[offset_mainbookinfo].authorname_ptr;
			else if (mode == 3)offset_mainbookinfo = arr_mainbookinfo[offset_mainbookinfo].pressname_ptr;
		}
	}
}