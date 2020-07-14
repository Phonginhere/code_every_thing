#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 Write a C program to store the names and scores of 5 students in a structure array. Sort the structure array in descending order of scores. Display the top 3 scores.
 (Bài t?p trong sách C_Assignment_3.pdf)
 */
struct Student {
    char name[100];
    int score;
};

int main(int argc, char * argv[]) {
    struct Student *person = (struct Student *)malloc(5 * sizeof(struct Student *));
    int i, j;
    for(i = 0 ; i < 5; i++){
        printf("So hoc sinh : %d\n", i+1);
        
        printf("Nhap ten = "); scanf("%s", (*(person+i)).name);
        printf("Nhap diem = "); scanf("%d", &((*(person+i)).score));
        
    }
    //Sap xep giam dan theo diem
    for(i = 0 ; i < 4; i++){
        for(j = i+1 ; j < 5; j++){
            if(((*(person+i)).score) < ((*(person+j)).score)){
                struct Student temp;
                temp = *(person+i);
                *(person+i) = *(person+j);
                *(person+j) = temp;
                
            }
        }
    }
    for (i = 0; i < 3; i++){
    	printf("Student %d", i+1);
    	printf("Ten : %s \n", (*(person+i)).name);
    	printf("Diem: %d \n", (*(person+i)).score);
	}
	return 0;
}
