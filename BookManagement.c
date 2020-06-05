#include"Header.h"
BOOK* BookManagement_1_BookInformationInput(BOOK* arr,BOOK* bookinfo,int len,int cnt) {
	if (len == 0) { 
		arr->RecordID = bookinfo->RecordID;
		arr->BookID = bookinfo->BookID;
		arr->LendOut = bookinfo->LendOut;
		arr->Total = bookinfo->Total;
		strcpy(arr->AuthorName, bookinfo->AuthorName);
		strcpy(arr->BookName, bookinfo->BookName);
		strcpy(arr->Press, bookinfo->Press);
		return arr; 
	}
	BOOK* new_arr = (BOOK*)malloc(sizeof(BOOK) * (len + cnt));
	BOOK* new_ptr = new_arr;
	if(arr!=NULL)for (BOOK* ptr = arr; (ptr - arr) < len; ptr++, new_ptr++) *new_ptr = *ptr;
	for (BOOK* inp_ptr = new_ptr; (inp_ptr - new_ptr) < cnt;inp_ptr++) {
		inp_ptr->RecordID = bookinfo->RecordID;
		inp_ptr->BookID= bookinfo->BookID;
		inp_ptr->LendOut = bookinfo->LendOut;
		inp_ptr->Total = bookinfo->Total;
		strcpy(inp_ptr->AuthorName, bookinfo->AuthorName);
		strcpy(inp_ptr->BookName, bookinfo->BookName);
		strcpy(inp_ptr->Press, bookinfo->Press);
	}
	arr = new_arr;
	return new_arr;
}
void BookManagement_2_BookInformationModify(BOOK* arr,int len,BOOK* info) {
	int offset = 0;
	offset = BinarySearch(arr,len,info->RecordID);
	arr[offset].LendOut = info->LendOut;
	arr[offset].Total = info->Total;
}
INDEX* BookManagement_By(BOOK* arr,int len,INDEX* index,int* cnt,int stat){
	int cnt2 = 0;
	*cnt = 0;
	if (stat == 2)index = RemoveDuplicate(arr, len, 2, cnt);
	else if (stat == 1) index = RemoveDuplicate(arr, len, 1, cnt);
	else if (stat == 3) index = RemoveDuplicate(arr, len, 3, cnt);
	for (INDEX* ptr = index; (ptr - index) < (*cnt); ptr++) {
		cnt2 = 0;
		for (BOOK* ptr_2 = arr; (ptr_2 - arr) < len; ptr_2++) if (strcmp(ptr->str, ptr_2->BookName) == 0) ptr_2->bookname_ptr = ++cnt2;
	}
	return index;
	free(cnt);
}
void PrintInquireResult(BOOK* arr, INDEX* index, int* cnt2, char* input, int next,int cnt_temp,int index_len,int hit,int ini,int len,int* cnt) {
	INDEX* ptr=(INDEX*)malloc(sizeof(INDEX));
	ptr = index;
	for (; (ptr - index) < *cnt; ptr++) {
		if (strcmp(ptr->str, input) == 0) {
			next = 0;
			cnt_temp = 0;
			index_len = 0;
			hit = 1;
			ini = ptr->ini;
			index_len = ptr->len;
			while (cnt_temp != index_len) {
				for (BOOK* ptr = arr; (ptr - arr) < len; ptr++) {
					if (cnt_temp == 0) {
						if (ptr->RecordID == ini) {
							printf("%d\t%d\t%s\t%s\t%s\t%d\t%d\t\n", ptr->RecordID, ptr->BookID, ptr->BookName, ptr->AuthorName, ptr->Press, ptr->LendOut, ptr->Total);
							cnt_temp++;
							next = ptr->bookname_ptr;
							next++;
						}
					}
				}
				for (BOOK* ptr = arr; (ptr - arr) < len; ptr++) {
					if (ptr->bookname_ptr == next) {
						printf("%d\t%d\t%s\t%s\t%s\t%d\t%d\t\n", ptr->RecordID, ptr->BookID, ptr->BookName, ptr->AuthorName, ptr->Press, ptr->LendOut, ptr->Total);
						(next)++;
						cnt_temp++;
					}
				}
			}
			if (hit == 0) printf("The item isn't exsist\n");
		}
	}
}