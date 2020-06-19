#include"Header.h"
int getBlockNumber(FILE* FP, int block_size) {
	fseek(FP, 0, SEEK_END);
	int cnt = ftell(FP) / block_size;
	rewind(FP);
	return cnt;
}
void InsertionSort(BOOK* arr, int len) {
	for (BOOK* p = arr + 1; (p - arr) < len; p++)
		for (BOOK* q = p - 1; q >= arr; q--)
			if ((q+1)->recordID < q->recordID) {
				BOOK* temp =(BOOK*)malloc(sizeof(BOOK)); 
				if (temp == NULL) {
					printf("Fail to apply for memory\n");
					exit(1);
				}
				else {
					strcpy(temp->authorname, q->authorname);
					temp->authorname_ptr = q->authorname_ptr;
					temp->bookID = q->bookID;
					strcpy(temp->bookname, q->bookname);
					temp->bookname_ptr = q->bookname_ptr;
					temp->lendout = q->lendout;
					strcpy(temp->press, q->press);
					temp->pressname_ptr = q->pressname_ptr;
					temp->recordID = q->recordID;
					temp->total = q->total;

					strcpy(q->authorname, (q + 1)->authorname);
					q->authorname_ptr = (q + 1)->authorname_ptr;
					q->bookID = (q + 1)->bookID;
					strcpy(q->bookname, (q + 1)->bookname);
					q->bookname_ptr = (q + 1)->bookname_ptr;
					q->lendout = (q + 1)->lendout;
					strcpy(q->press, (q + 1)->press);
					q->pressname_ptr = (q + 1)->pressname_ptr;
					q->recordID = (q + 1)->recordID;
					q->total = (q + 1)->total;

					strcpy((q + 1)->authorname, temp->authorname);
					(q + 1)->authorname_ptr = temp->authorname_ptr;
					(q + 1)->bookID = temp->bookID;
					strcpy((q + 1)->bookname, temp->bookname);
					(q + 1)->bookname_ptr = temp->bookname_ptr;
					(q + 1)->lendout = temp->lendout;
					strcpy((q + 1)->press, temp->press);
					(q + 1)->pressname_ptr, temp->pressname_ptr;
					(q + 1)->recordID = temp->recordID;
					(q + 1)->total = temp->total;

					free(temp);
				}
			}
			else break;
}
int BinarySearch(BOOK* arr,int len,int key) {
		int lo = 0;
		int hi = len - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (key < (arr+mid)->recordID)hi = mid - 1;
			else if (key > (arr+mid)->recordID)lo = mid + 1;
			else return mid;
		}
		return -1;
}