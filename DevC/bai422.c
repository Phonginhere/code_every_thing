#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int C, F;
	printf("Input C:"); scanf("%d", &C);
	F = C * 1.8 + 32;
	printf("Expected Output :\n");
	printf("Input a temperature (in Centigrade): %d", F);
	return 0;
}	
