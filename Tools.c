#include"Header.h"
int GetNumberOfBlock(FILE* FP, int block_size) {
	fseek(FP, 0, SEEK_END);
	int cnt = ftell(FP) / block_size;
	rewind(FP);
	return cnt;
}
void InsertionSort(BOOK* arr, int len) {
	for (BOOK* p = arr + 1; (p - arr) < len; p++)
		for (BOOK* q = p - 1; q >= arr; q--)
			if ((q+1)->RecordID < q->RecordID) {
				BOOK* temp =(BOOK*)malloc(sizeof(BOOK));
				strcpy(temp->AuthorName, q->AuthorName);
				temp->authorname_ptr = q->authorname_ptr;
				temp->BookID = q->BookID;
				strcpy(temp->BookName, q->BookName);
				temp->bookname_ptr = q->bookname_ptr;
				temp->LendOut = q->LendOut;
				strcpy(temp->Press, q->Press);
				temp->press_ptr = q->press_ptr;
				temp->RecordID = q->RecordID;
				temp->Total = q->Total;

				strcpy(q->AuthorName, (q+1)->AuthorName);
				q->authorname_ptr = (q+1)->authorname_ptr;
				q->BookID = (q+1)->BookID;
				strcpy(q->BookName, (q+1)->BookName);
				q->bookname_ptr = (q+1)->bookname_ptr;
				q->LendOut = (q+1)->LendOut;
				strcpy(q->Press, (q+1)->Press);
				q->press_ptr = (q+1)->press_ptr;
				q->RecordID = (q+1)->RecordID;
				q->Total = (q+1)->Total;
				
				strcpy((q + 1)->AuthorName,temp->AuthorName);
				(q + 1)->authorname_ptr=temp->authorname_ptr;
				(q + 1)->BookID=temp->BookID ;
				strcpy((q + 1)->BookName,temp->BookName);
				(q + 1)->bookname_ptr=temp->bookname_ptr;
				(q + 1)->LendOut=temp->LendOut;
				strcpy((q + 1)->Press,q->Press);
				(q + 1)->press_ptr,temp->press_ptr;
				(q + 1)->RecordID=temp->RecordID;
				(q + 1)->Total=temp->Total;
				
				free(temp);
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
LOAR* AddNewNode(LOAR* head, LOAR* newnode) {
	if (head->next == NULL) {
		LOAR* realnode = (LOAR*)malloc(sizeof(LOAR));
		realnode->next = NULL;
		realnode->bookID = newnode->bookID;
		realnode->uid = newnode->uid;
		strcpy(realnode->lendout_date, newnode->lendout_date);
		head->next = realnode;
	}
	else {
		LOAR* realnode = (LOAR*)malloc(sizeof(LOAR));
		realnode->next = NULL;
		realnode->bookID = newnode->bookID;
		realnode->uid = newnode->uid;
		strcpy(realnode->lendout_date, newnode->lendout_date);
		LOAR* ptr_temp = (LOAR*)malloc(sizeof(LOAR));
		ptr_temp = head;
		while (ptr_temp->next != NULL) {
			ptr_temp = ptr_temp->next;
		}
		ptr_temp->next = newnode;
	}
	return head;
}