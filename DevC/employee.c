#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Employee {
	int number;
    int working_days;
    int daily_salary;
};
int N;
struct Employee* input(){
	struct Employee *employee = (struct Employee *)malloc(N * sizeof(struct Employee));
	int i;
	printf("nhap tong so nhan vien: "); scanf("%d", &N);
	for (i = 0; i < N; i++){
Label1:printf("Nhan vien thu [%d]\n", i+1);
		printf("(nhap lai))Nhan vien thu: "); scanf("%d", &(*(employee+i)).number);
		printf("Nhap so ngay lam: "); scanf("%d", &(*(employee+i)).working_days);
		printf("Nhap luong trong ngay: "); scanf("%d", &(*(employee+i)).daily_salary);
		if ((*(employee+i)).working_days < 1 || (*(employee+i)).working_days > 21 && (*(employee+i)).daily_salary < 10 || (*(employee+i)).daily_salary > 100){
			printf("ko hop le, nhap lai\n");
			goto Label1;
		}	
	}
	return employee;
}
void display(struct Employee* employee) {
    int i;
    printf("+--------------------------------------+\n");
    printf("| STT | So ngay lam | Luong trong ngay |\n");
    printf("+--------------------------------------+\n");
    for (i = 0; i < N; i++) {
        printf("|%-5d", (*(employee+i)).number);
        printf("|%-13d", (*(employee+i)).working_days);
        printf("|%-18.2d", (*(employee+i)).daily_salary);
    }
    printf("+----------------------------------------------+\n");
}

void sort(struct Employee* employee) {
    int i, j;
    for(i = 0; i < N-1; i++){
        for (j = i + 1; j < N; j++) {
            if(strcmp( (*(employee+i)).number), ((*(employee + j)).number) > 0) {
                struct Employee temp;
                temp = *(employee + i);
                *(employee + i) = *(employee + j);
                *(employee + j) = temp;
            }
        }
    }
    display(employee);
}

int main(int argc, char *argv[]) {
	struct Employee* employee = NULL;
	int select;
Label1:printf("+---------------------+\n");
	printf("|1.Input|2.Sort|3.Exit|\n");
	printf("+---------------------+\n");
	printf("nhap so: "); scanf("%d", &select);
	switch(select){
		case 1: employee = input();
				goto Label1;
				break;
		case 2: sort(employee);
				goto Label1;
				break;
		case 3: break;
	}
	return 0;
}

