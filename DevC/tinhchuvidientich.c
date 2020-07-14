#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float b, c, d;
	printf("nhap c: "); scanf("%f", &c);
	b = c * 2 * PI;
	d = pow(c, 2) * PI;
	printf("b = %f", b);
	printf("d = %f", d);
	return 0;
}
