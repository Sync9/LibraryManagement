#include"Header.h"
BOOK* BinarySearchForFile(int recordID, char* path) {
	FILE* fp = fopen("D:\\MainBookInfo.dat", "rb");
	if (fp == NULL) {
		printf("Fail to open %s\n", path);
		exit(1);
	}
	BOOK* temp = (BOOK*)malloc(sizeof(BOOK));
	if (temp == NULL) {
		printf("Fail to apply memory\n");
		exit(1);
	}
	int lo = 1;
	int hi = getBlockNumber(fp, sizeof(BOOK));
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		fseek(fp, +(long)(mid - 1) * sizeof(BOOK), SEEK_SET);
		fread(temp, sizeof(BOOK), 1, fp);
		if (recordID < temp->recordID)hi = mid - 1;
		else if (recordID > temp->recordID)lo = mid + 1;
		else {
			return temp;
		}
	}
	return NULL;
}