#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, j;
    printf("Test Data :\n");
    printf("Press Input the number (Table to be calculated) :"); scanf("%d", &n);
    printf("Sample Output:\n");
    printf("Input the number (Table to be calculated) : %d", n);
    for(j=1;j<=10;j++)
   {
     printf("%d X %d = %d \n",n,j,n*j);
   }
	return 0;
}
