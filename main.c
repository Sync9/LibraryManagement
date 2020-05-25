#include"Header.h"
int main()
{
	char UserFile[] = { PATHU };
	char ReaderFile[] = { PATHR };
	char BookMainFile[] = { PATHMB };
	char BookNameIndex[] = {PATHBNI};
	char AuthorNameIndex[] = { PATHANI };
	char PressIndex[] = { PATHPI };
	char LOARFile[] = { PATHLR };
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
	int* cnt_bookname = (int*)malloc(sizeof(int));
	*cnt_bookname = cnt;
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
	int* cnt_authorname = (int*)malloc(sizeof(int));
	*cnt_authorname = cnt;
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
	int* cnt_pressname = (int*)malloc(sizeof(int));
	*cnt_pressname = cnt;
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
	if (Login(cnt, UINF, Signin) == 0) { 
		USER* CURU = (USER*)malloc(sizeof(USER));
		if (CURU == NULL) {
			printf("Fail to apply for memory\n");
			exit(1);
		}
		else {
			CURU = UINF->NEXT;
			while (CURU != NULL) {
				fwrite(CURU, sizeof(USER), 1, FPU);
				CURU = CURU->NEXT;
			}
			USER* PREU = (USER*)malloc(sizeof(USER));
			if (PREU == NULL) {
				printf("Fail to apply for memory\n");
				exit(1);
			}
			else {
				while (CURU != NULL) {
					PREU = CURU;
					CURU = CURU->NEXT;
					free(PREU);
				}
				fclose(FPU);
			}
		}
		if (arr_mainfile != NULL) {
			fwrite(arr_mainfile, sizeof(BOOK), len, FPMB);
			free(arr_mainfile);
		}
		if (arr_bookname != NULL) {
			fwrite(arr_bookname, sizeof(INDEX), *cnt_bookname, FPBNI);
			free(arr_bookname);
			free(cnt_bookname);
		}
		if (arr_authorname != NULL) {
			fwrite(arr_authorname, sizeof(INDEX), *cnt_authorname, FPANI);
			free(arr_authorname);
			free(cnt_authorname);
		}
		if (arr_press != NULL) {
			fwrite(arr_press, sizeof(INDEX), *cnt_pressname, FPPI);
			free(arr_press);
			free(cnt_pressname);
		}
		printf("All the information needed to be saved has been saved\n");
		fclose(FPMB);
		fclose(FPPI);
		fclose(FPBNI);
		fclose(FPANI);
		exit(1); 
	}
	else {
		int ALT_Lev1 = 0;//ALT=AlternativeFeature
		int ALT_Lev2 = 0;//ALT_Lev2=AlternativeFeatureLevel2¡¡
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
				printf("Fail to open the file named LOARInformation\n");
				exit(1);
			}
			LOAR* LRINF = (LOAR*)malloc(sizeof(LOAR));
			LRINF = LOARInformationLinkedListCreat(FPLR, LOARFile, LRINF);
			LibraryAdministrator(ALT_Lev1, ALT_Lev2, UINF, RINF, LRINF,FPU, FPR,FPMB,FPPI,FPBNI,FPANI,FPLR,arr_mainfile,len,arr_authorname,arr_bookname,arr_press);
		}
		else if (Signin->UL == 2)	SystemAdministrator(ALT_Lev1, ALT_Lev2, UINF, FPU, FPMB, FPPI, FPBNI, FPANI, arr_mainfile, len, arr_authorname, arr_bookname, arr_press);
		else if (Signin->UL == 1)	Reader(ALT_Lev1, ALT_Lev2, Signin->UID, UINF,FPU,FPMB, FPPI, FPBNI, FPANI, arr_mainfile, len, arr_authorname, arr_bookname, arr_press);
		
	}
	return 0;
}
