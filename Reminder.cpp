#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int main(){
	int menu1;
	char namaFile[100];
	//menu1
	do{
		printf("Pilih:\n");
		printf("1. Write\n");
		printf("2. Append\n");
		printf("3. Read\n");
		printf("4. Selesai\n");
		printf("0. Exit\n");
		printf("Untuk setiap input, apabila mengetik 0 akan kembali ke halaman sblmnya\n");
		printf(">> ");
		scanf("%d",&menu1);
		system("cls");
		if(menu1 == 1){
			printf("Input file pelajaran (format: fileName.txt): ");
			scanf("%s",namaFile);
			if(strcmp(namaFile,"0") == 0){
				system("cls");
				menu1 = 5;
			}
			else{
				FILE *A = fopen("listFile.txt", "a");
				fprintf(A, "%s\n", namaFile);
				FILE *write = fopen(namaFile,"w");
				printf("File successfully created, press any key to continue...");
				fclose(write);
				fclose(A);
				getch();
				system("cls");
				menu1 = 5;
			}
		}
		else if(menu1 == 2){
			char temporal[100];
			char tambah[1000];
			int nomor = 1;
			int temp = 0;
			FILE *B = fopen("listFile.txt","r");
			printf("Daftar list file yg ada: \n");
			while(fscanf(B," %s",temporal)==1){
				printf("%d. %s\n",nomor, temporal);
				nomor++;
			}
			printf("\nInput nama file (bukan nomor) dr list tersebut utk ditambahin: ");
			scanf("%s",namaFile);
			if(strcmp(namaFile,"0") == 0){
				system("cls");
				menu1 = 5;
			}
			else{
				FILE *append = fopen(namaFile,"a");
				printf("\n\nMasukkan yg mau ditambahkan dengan format: \n");
				printf("materi(GSLC,dll);lokasi(forum/assignment);deadline(dd/mm/yy)\n\n");
				printf(">> ");
				scanf(" %[^\n]", tambah);
				if(strcmp(tambah,"0") == 0){
					system("cls");
					menu1 = 5;
				}
				else{
					fprintf(append, "%s\n",tambah);
					printf("File successfully appended, press any key to continue...");
					fclose(B);
					fclose(append);
					getch();
					system("cls");
					menu1 = 5;
				}
			}
		}
		else if(menu1 == 3){
			char file[100];
			char string[1000];
			int num = 1;
			printf("List file dan isinya:\n");
			FILE *C = fopen("listFile.txt","r");
			while(fscanf(C," %s",file) == 1){
				num = 1;
				FILE *temp = fopen(file,"r");
				printf("%s:\n",file);		
				while(fscanf(temp, " %s", string) == 1){
					printf("%d. %s\n",num, string);
					num++;
				}
				printf("\n\n");
				fclose(temp);
			}
			printf("Press any key to continue...");
			fclose(C);
			getch();
			system("cls");menu1 = 5;
		}
		else if(menu1 == 4){
			char file[100];
			char string[1000];
			char kelar[1000];
			int num = 1;
			printf("List file dan isinya:\n");
			FILE *C = fopen("listFile.txt","r");
			while(fscanf(C," %s",file) == 1){
				num = 1;
				FILE *temp = fopen(file,"r");
				printf("%s:\n",file);		
				while(fscanf(temp, " %s", string) == 1){
					printf("%d. %s\n",num, string);
					num++;
				}
				printf("\n\n");
				fclose(temp);
			}
			printf("Ketik tugas yg sudah selesai dgn format:\npelajaran;materi(GSLC,dll);lokasi(forum/assignment);deadline(dd/mm/yy)\n\n>> ");
			FILE *done = fopen("done.txt","a");
			scanf(" %[^\n]",kelar);
			if(strcmp(kelar,"0") == 0){
				system("cls");
				menu1 = 5;
			}
			else{
				fprintf(done,"%s\n",kelar);
				printf("Press any key to continue...");
				fclose(done);
				fclose(C);
				getch();
				system("cls");
				menu1 = 5;
			}
		}
	}while(menu1<0||menu1>4);
		
	return 0;
}
