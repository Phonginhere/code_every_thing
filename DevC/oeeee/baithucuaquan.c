#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student {
    char name[100];
    unsigned int score;
};
int N=5;//bien toan cuc, co tac dung ben trong main.c
struct Student *input(){
    struct Student *student = (struct Student *)malloc(N * sizeof(struct Student));
    int i;
    for (i = 0; i < N; i++){
    	printf("Enter Student's %d name : \n",i+1);scanf("%s", (*(student+i)).name);
    	printf("Enter Student's score : \n");scanf("%d", &((*(student+i)).score));
    }
    return student;
}
void sort(struct Student *student){
	int i, j;
    struct Student *ptr = student;
    for(i = 0; i < N-1; i++){
        for(j = i + 1; j < N; j++){
             if((*(ptr + i)).score > (*(ptr + j)).score){
					struct Student temp;
					temp = *(ptr + i);	
					*(ptr + i) = *(ptr + j);	
					*(ptr + j)= temp;
				}
            }
        }
    printf("Sort finished\n");
}
void display(struct Student *student) {
    int i;
    for(i = N-1; i >N-4; i--){
        printf("Student's score top :%d\n", (*(student+i)).score);
    }
}

int main(int argc, char * argv[]) {
	struct Student *student = NULL;
    student = input();
    sort(student);
    display(student);
  	return 0;
}
