#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a;
	float b;
	float c;
	printf("nhap a: ");
	scanf("%f", &a);
	printf("Nhap b: ");
	scanf("%f", &b);
	c = a + b;
	printf("ket qua la: %.0f", c);
}
