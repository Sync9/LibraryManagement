#include"Header.h"
int main()
{
	char UserFile[] = { PATHU };
	char ReaderFile[] = { PATHR };
	char BookMainFile[] = { PATHMB };
	char BookNameIndex[] = {PATHBNI};
	char AuthorNameIndex[] = { PATHANI };
	char PressIndex[] = { PATHPI };
	char LendOutAndReturnFile = { PATHLR };
	/************************************************************/
	FILE* FPMB = fopen(PATHMB, "ab+");
	if (FPMB == NULL) {
		printf("Fail to open the file named UserInformation:(\n");
		exit(1);
	}
	int cnt =GetNumberOfBlock(FPMB,sizeof(BOOK));
	int len = cnt;
	BOOK* arr_mainfile = (BOOK*)malloc(sizeof(BOOK) * cnt);
	if (cnt == 0) {
		free(arr_mainfile);
		arr_mainfile = NULL;
	}
	if(arr_mainfile!=NULL) fread(arr_mainfile, sizeof(BOOK), cnt, FPMB);
	fclose(FPMB);
	FPMB = fopen(PATHMB, "wb+");
	/************************************************************/
	FILE* FPBNI = fopen(PATHBNI, "ab+");
	if (FPBNI == NULL) {
		printf("Fail to open the file named UserInformation:(\n");
		exit(1);
	}
	cnt = GetNumberOfBlock(FPBNI, sizeof(INDEX));
	INDEX* arr_bookname = (INDEX*)malloc(sizeof(INDEX)*cnt);
	if (cnt == 0) {
		free(arr_bookname);
		arr_bookname = NULL;
	}
	if(arr_bookname!=NULL)fread(arr_bookname, sizeof(INDEX), cnt, FPBNI);
	fclose(FPBNI);
	FPBNI = fopen(PATHBNI, "wb+");
	/*************************************************************/
	FILE* FPANI = fopen(PATHANI, "ab+"); 
	if (FPANI == NULL) {
		printf("Fail to open the file named UserInformation:(\n");
		exit(1);
	}
	cnt = GetNumberOfBlock(FPANI, sizeof(INDEX));
	INDEX* arr_authorname = (INDEX*)malloc(sizeof(INDEX)*cnt);
	if (cnt == 0) {
		free(arr_authorname);
		arr_authorname = NULL;
	}
	if(arr_authorname!=NULL)fread(arr_authorname, sizeof(INDEX), cnt, FPANI);
	fclose(FPANI);
	FPANI = fopen(PATHANI, "wb+");
	/************************************************************/
	FILE* FPPI = fopen(PATHPI, "ab+");
	if (FPPI == NULL) {
		printf("Fail to open the file named UserInformation:(\n");
		exit(1);
	}
	cnt = GetNumberOfBlock(FPPI, sizeof(INDEX));
	INDEX* arr_press = (INDEX*)malloc(sizeof(INDEX) * cnt);
	if (cnt == 0) {
		free(arr_press);
		arr_press = NULL;
	}
	if(arr_press!=NULL)fread(arr_press, sizeof(INDEX), cnt, FPPI);
	fclose(FPPI);
	FPPI = fopen(PATHPI, "wb+");
	/************************************************************/
	FILE* FPU = fopen(PATHU, "ab+");
	if (FPU == NULL) {
		printf("Fail to open the file named UserInformation:(\n");
		exit(1);
	}
	USER* UINF = (USER*)malloc(sizeof(USER));
	UINF=USERInformationLinkedListCreat(FPU,UserFile,UINF);
	USER* Signin = (USER*)malloc(sizeof(USER));
	cnt = 0;
	if (Login(cnt, UINF, Signin) == 0) exit(1);
	else {
		int ALT_Lev1 = 0;//ALT=AlternativeFeature
		int ALT_Lev2 = 0;//ALT_Lev2=AlternativeInFeature
		if (Signin->UL == 3) {
			FILE* FPR = fopen(PATHR, "ab+");
			if (FPR == NULL) {
				printf("Fail to open the file named ReaderInformation:(\n");
				exit(1);
			}
			READER* RINF = (READER*)malloc(sizeof(READER));
			RINF = READERInformationLinkedListCreat(FPR, ReaderFile, RINF);
			FILE* FPLR = fopen(PATHLR, "ab+");
			if (FPLR == NULL) {
				printf("Fail to open the file named LendOutAndReturnInformation\n");
				exit(1);
			}
			LendOutAndReturn* LRINF = (LendOutAndReturn*)malloc(sizeof(LendOutAndReturn));
			LRINF = LendOutAndReturnInformationLinkedListCreat(FPLR, LendOutAndReturnFile, LRINF);
			LibraryAdministrator(ALT_Lev1, ALT_Lev2, UINF, RINF, LRINF,FPU, FPR,FPMB,FPPI,FPBNI,FPANI,FPLR,arr_mainfile,len,arr_authorname,arr_bookname,arr_press);
		}
		else if (Signin->UL == 2)	SystemAdministrator(ALT_Lev1, ALT_Lev2, UINF, FPU, FPMB, FPPI, FPBNI, FPANI, arr_mainfile, len, arr_authorname, arr_bookname, arr_press);
		else if (Signin->UL == 1)	Reader(ALT_Lev1, ALT_Lev2, Signin->UID, UINF,FPU,FPMB, FPPI, FPBNI, FPANI, arr_mainfile, len, arr_authorname, arr_bookname, arr_press);
		
	}
	return 0;
}