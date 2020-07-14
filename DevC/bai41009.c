#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	unsigned int a, b, c;
	printf("nhap a:"); scanf("%d", &a);
	printf("\nnhap b: "); scanf("%d", &b);
	printf("\nnhap c: "); scanf("%d", &b);
	if ( c < a + b && b < a + c && c < b + c ){
		printf("\nday la tam giac");
		int p; p = (a + b + c) / 2; printf("\nnua chu vi la: %d", p);
		float s; s = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("\ndien tich cua tam giac la: %f", s);
	} else {
		printf("\nkhong phai la tam giac");
	}
	return 0;
}
