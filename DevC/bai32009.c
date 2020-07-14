#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int N, rows, columns;
	printf("Enter N ="); scanf("%d", &N);
	for(rows = 1; rows <= 10000000000; rows++) {
		int multiply = N * rows;
		printf("%d * %d = %d\n", N, rows, multiply);
	}
	return 0;
}
