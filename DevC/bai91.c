#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j;
    printf("Press N: "); scanf("%d", %N);
    for (i = 0; i <= N; i++){
        printf("Press [%d]: ", i+1); scanf ("%d", &j);
    }
    if(j % 2 == 0){
        for(i = 0; i <= N; i++){
        printf("Negative numbers [%d]: %d", i+1, j);
        }
    }else if(j == 0){
        for(i = 0; i <= N; i++){
        printf("Zero numbers[%d]: %d", i+1, j);
        }
    }else{
        for(i = 0; i <= N; i++){
        printf("Positive numbers [%d]: %d", i+1, j);
        }
    }
	return 0;
}
