#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student{
	char name [25];
	unsigned int age;
};
int N;
struct Student* input(){
	struct Student* student = (struct Student*)malloc(N * sizeof(struct Student));
	int i;
	printf("nhap so nguoi: "); scanf("%d", &N);
	for (i = 0; i < N; i++){
	printf("nguoi thu [%d]\n", i+1);
	printf("nhap ten: "); scanf("%s", (*(student+i)).name);
	printf("nhap tuoi: "); scanf("%d", &(*(student+i)).age);
}
	return student;
}
int main(int argc, char *argv[]) {
	struct Student* student;
	int choice;
	printf("nhap so: "); scanf("%d", &choice);
	switch(choice){
		case '1': student = input();
					break;
	}
	return 0;
}
