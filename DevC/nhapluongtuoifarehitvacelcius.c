#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b;
	float c, d, e, f;
	printf("nhap luong: "); scanf("%d", &a);
	printf("nhap tuoi: "); scanf("%d", &b);
	printf("luong: %d, tuoi: %d", a, b);
	//-------------------------------------//
	printf("\nnhap Farehit: "); scanf("%f", &c);
	printf("nhap Celcius: "); scanf("%f", &d);
	e = (c - 32) * 5 / 9 ;
	printf("Farehit = %f --> Celcius = %f", c, e);
	f = (9/5 * d) + 32;
	printf("\nCelcius = %f --> Farehit = %f", d, f);
	return 0;
}
