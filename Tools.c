#include"Header.h"
int GetNumberOfBlock(FILE* FP, int block_size) {
	fseek(FP, 0, SEEK_END);
	int cnt = ftell(FP) / block_size;
	rewind(FP);
	return cnt;
}
void InsertionSort(int* arr, int len) {
	for (int* p = arr + 1; (p - arr) < len; p++)
		for (int* q = p - 1; q >= arr; q--)
			if (*(q + 1) > *q) {
				int temp = *q;
				*q = *(q + 1);
				*(q + 1) = temp;
			}
			else break;
}
int BinarySearch(BOOK* arr,int len,int key) {
		int lo = 0;
		int hi = len - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (key < (arr+mid)->RecordID)hi = mid - 1;
			else if (key > (arr+mid)->RecordID)lo = mid + 1;
			else return mid;
		}
		return -1;
}
INDEX* RemoveDuplicate(BOOK* arr,int len,int stat,int* cnt) {
	INDEX* index_new = (INDEX*)malloc(sizeof(INDEX)*len);
	INDEX* ptr_index = index_new;

	for (BOOK* ptr_arr = arr; (ptr_arr - arr) < len; ptr_arr++,ptr_index++) 
		if(stat==2)strcpy(ptr_index->str,ptr_arr->AuthorName);
		else if(stat==1)strcpy(ptr_index->str, ptr_arr->BookName);
		else if (stat == 3)strcpy(ptr_index->str, ptr_arr->Press);

	for (INDEX* ptr = index_new; (ptr - index_new) < len; ptr++)
		for (INDEX* ptr_1 = index_new; (ptr_1 - index_new) < len; ptr_1++) {
			if (ptr == ptr_1) continue;
			if (strcmp(ptr->str, ptr_1->str) == 0) strcpy(ptr_1->str, "\0");
			if (strcmp(ptr_1->str,"\0" ) == 0) continue;
		}

	for (INDEX* ptr = index_new; (ptr - index_new) < len; ptr++)
		if (strcmp(ptr->str, "\0") != 0) (*cnt)++;
	INDEX* index_ini = (INDEX*)malloc(sizeof(INDEX) * (*cnt));
	INDEX* ptr_ini = index_ini;
	for (INDEX* ptr = index_new;(ptr_ini - index_ini) < (*cnt);)
			if (strcmp(ptr->str, "\0") == 0) continue;
			else {
				strcpy(ptr_ini->str, ptr->str);
				ptr_ini++;
				ptr++;
			}
	free(index_new);
	return index_ini;
}
INDEX* CreatIndex(BOOK* arr,int len,INDEX* index,int* cnt,int stat) {
	if (index == NULL&&arr==NULL) return 0;
	else {
		*cnt = 0;
		int cnt2 = 0;
		index = BookManagement_By(arr, len, index,cnt,stat);
		for (INDEX* ptr = index; (ptr - index) < *cnt; ptr++) {
			cnt2 = 0;
			for (BOOK* ptr_2 = arr; (ptr_2 - arr) < len; ptr_2++) {
				if (stat == 1) {
					if (strcmp(ptr_2->BookName, ptr->str) == 0) {
						if (cnt2 == 0) ptr->ini = ptr_2->RecordID;
						ptr_2->bookname_ptr = ++cnt2;
					}
					else ptr_2->bookname_ptr = 0;
				}
				else if (stat == 2) {
					if (strcmp(ptr_2->AuthorName, ptr->str) == 0) {
						if (cnt2 == 0) ptr->ini = ptr_2->RecordID;
						ptr_2->authorname_ptr = ++cnt2;
					}
					else ptr_2->authorname_ptr = 0;
				}
				else if (stat == 3) {
					if (strcmp(ptr_2->Press, ptr->str) == 0) {
						if (cnt2 == 0) ptr->ini = ptr_2->RecordID;
						ptr_2->press_ptr = ++cnt2;
					}
					else ptr_2->press_ptr = 0;
				}

			}
			ptr->len = cnt2;
		}
		
		return index;
		free(cnt);
	}
}
LendOutAndReturn* AddNewNode(LendOutAndReturn* head, LendOutAndReturn* newnode) {
	if (head->next == NULL) {
		LendOutAndReturn* realnode = (LendOutAndReturn*)malloc(sizeof(LendOutAndReturn));
		realnode->next = NULL;
		realnode->bookID = newnode->bookID;
		realnode->uid = newnode->uid;
		strcpy(realnode->lendout_date, newnode->lendout_date);
		head->next = realnode;
	}
	else {
		LendOutAndReturn* realnode = (LendOutAndReturn*)malloc(sizeof(LendOutAndReturn));
		realnode->next = NULL;
		realnode->bookID = newnode->bookID;
		realnode->uid = newnode->uid;
		strcpy(realnode->lendout_date, newnode->lendout_date);
		LendOutAndReturn* ptr_temp = (LendOutAndReturn*)malloc(sizeof(LendOutAndReturn));
		ptr_temp = head;
		while (ptr_temp->next != NULL) {
			ptr_temp = ptr_temp->next;
		}
		ptr_temp->next = newnode;
	}
	return head;
}