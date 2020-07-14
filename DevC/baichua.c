#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Mark{
	float math;
	float chemist;
	float physics;
};
struct Student{
	char name [25];
	char hometown[25];
	unsigned int age;
	struct Mark* score;
};
int N;
struct Student* input(){
	struct Student* student = (struct Student*)malloc(N * sizeof(struct Student));
	struct Mark* mark = (struct Mark*)malloc(N * sizeof(struct Mark));
	int i;
	printf("Enter number student: "); scanf("%d", &N);
	for(i = 0; i < N; i++){
		printf("Student [%d]\n", i+1);
		printf("Press student name: "); scanf("%s", (student)->name);
		printf("Press student hometown: "); scanf("%s", (student)->hometown);
		printf("Press student age: "); scanf("%d", &(student)->age);
		printf("Press student math mark: "); scanf("%f", &(mark)->math);
		printf("Press student chemist mark: "); scanf("%f", &(mark)->chemist);
		printf("Press student physics mark: "); scanf("%f", &(mark)->physics);
	}
}
int main(int argc, char *argv[]){
	
	return 0;
}
