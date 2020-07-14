#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[1000],i;
	int n = 10;  
		printf("Input 10 elements in the array:\n");
    	printf("element - %d: ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
 	printf("Expected Output :\n")
    printf("\nElements in array are: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", a[i]);
    }
	return 0;
}
