#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// error printf phan tang luong va 10 nam
struct person_all{
	char id[100];
	char name[50];
	unsigned int salary [100];
	char date [50];
	unsigned int years [100];
};
long N, i;
struct person_all *input(){
	/*
	printf("So thanh vien: "); scanf("%d", &N);
	struct person_all *Person = (struct person_all *)malloc(N * sizeof(struct person_all));
	int i;
	for (i = 0; i < N; i++){
		printf("Person number %d: \n", i+1);
		printf("Nhap ten thanh vien: "); scanf("%s", (*(Person+i)).id);
		printf("Nhap tuoi thanh vien"), scanf("%s", &((*(Person+i)).name));
		printf("Nhap nghe nghiep thanh vien "); scanf("%s", (*(Person+i)).date);
	} */
	
			printf("So thanh vien: "); scanf("%d", &N);
			struct person_all *nhanvien = (struct person_all*)malloc(N * sizeof(struct person_all));
			int i;
			for(i = 0; i < N; i++){
				printf("nguoi thu %d\n", i+1);
				printf("nhap id: "); scanf("%s", (*(nhanvien+i)).id);
				printf("nhap ten: "); scanf("%s", (*(nhanvien+i)).name);
				printf("nhap luong: "); scanf("%d", &(*(nhanvien+i)).salary);
				printf("nhap thoi gian tham gia: "); scanf("%s", (*(nhanvien+i)).date);
				printf("nhap nam: "); scanf("%d", &(*(nhanvien+i)).years);
				
			} 
			return nhanvien;
}
void tangluong(struct person_all* nhanvien){
	int i;
	if((((*(nhanvien+i))).salary) <= 2000){
				printf("tang them 15%");
				for(i = 0; i < N; i++){
				puts((*(nhanvien+i)).id);
				puts((*(nhanvien+i)).name);
					}
		} else if ((*(nhanvien+i)).salary  > 2000 && (*(nhanvien+i)).salary <= 5000) {
			printf("tang them 10%");
			for(i = 0; i < N; i++){
			puts((*(nhanvien+i)).id);
			puts((*(nhanvien+i)).name);
			}
		} else if ((((*(nhanvien+i)).salary)) > 5000){
			printf("ko tang luong them: ");
			for(i = 0; i < N; i++){
			puts((*(nhanvien+i)).id);
			puts((*(nhanvien+i)).name);			
		}
	}
}
void year(struct person_all* nhanvien){
	int i;
	if ((*(nhanvien+i)).years >= 10 ){
			puts((*(nhanvien+i)).id);
			puts((*(nhanvien+i)).name);
			}
	
}
int main(int argc, char *argv[]) {
	unsigned int select;
	struct person_all *nhanvien = (struct person_all *)malloc(N * sizeof(struct person_all));
	Label1:printf("1.nhap thong tin nhan vien\n");
	printf("2.thong tin tang luong");
	printf("\n3.nhung nguoi lam viec 10 nam\n");	
	printf("nhap so: "); scanf("%d", &select);
	switch(select){
		case 1:
				 nhanvien = input();
				goto Label1;
				break;
		case 2: tangluong(nhanvien);
				goto Label1;
				break;
		case 3: year(nhanvien);
				goto Label1;
				break; 
		case 4: break;
		default: goto Label1;
				break;
}
return 0;
}
