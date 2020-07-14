#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int N, a, b = 1;
	printf("nhap a: ");scanf("%d", &a);
	for (N = 1; N <= a; N++) {
		b = b * N;
	} printf("giai thua cua %d la %d\n", a, b);
	return 0;
}
