#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j;
    printf("Test Data : \n"); scanf("%d", &i);
    printf(""); scanf("%d", &j);
    printf("Expected Output :\n");
    if (i < j){
        printf("You can booked your profit amount : %d\n", j-i);
    }else{
        printf("You can't booked your profit amount :");
    }
    return 0; 
}
