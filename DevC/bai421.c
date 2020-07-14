#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
    printf("Test Data :"); scanf("%d", &i);
    printf("Expected Output :\n");
    if(i < 18){
        printf("Congratulation! You are eligible for casting your vote.\n");
    }else{
        printf("Sorry! You are not eligible for casting your vote.")
    }
	return 0;
}
