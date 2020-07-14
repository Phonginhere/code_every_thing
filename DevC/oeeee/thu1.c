#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Student{
	char name[50];
	unsigned int age;
};
int N;
struct Student* input(){
	int i; 
	printf("nhap so hoc sinh: "); scanf("%d", &N);
	struct Student* student = (struct Student*)malloc(N * sizeof(struct Student));
			for(i = 0; i < N; i++){
				printf("hoc sinh thu %d\n", i+1);
				printf("nhap ten: "); scanf("%s", (*(student+i)).name);
				printf("nhap tuoi: "); scanf("%d", &(*(student+i)).age); 
				
			}
			return student;
}
void sort(struct Student* student){
	int i, j;
    for(i = 0; i < N-1; i++){
        for(j = i+1; j < N; j++){
            if((student+i)->age < (student+j)->age){
                struct Student temp;
                temp = *(student+i);
                *(student+i) = *(student+j);
                *(student+j) = temp;
            }
        }
    }
    //lay ra phan tu dau tien
    printf("Ten sinh vien co tuoi cao nhat: %s, tuoi: %d\n", student->name, student->age);
}
int main(int argc, char *argv[]){
Label1:printf("+---------------------------------+\n");
	printf("|1.Nhap thong tin|2.So sanh|3.Thoat\n");
	printf("+---------------------------------+\n");
	struct Student* student;
	int select;
	printf("nhap so: "); scanf("%d", &select);
	switch(select){
		case 1: student = input();
					goto Label1;
					break;
		case 2: sort(student);
				goto Label1;
				break;	
		case 3: break;
	}
	return 0;
}

