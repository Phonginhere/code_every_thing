#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	float a, b, c, delta;
	do{
	printf("nhap a: "); scanf("%f", &a);
	} while (a==0);
	printf("nhap b: ");
	scanf("%f", &b);
	printf ("nhap c: ");
	scanf("%f", &c);
	delta = pow(b, 2) - 4 * a *c;
	if (delta < 0){
		printf("phuong trinh vo nghiem");
	} else if (delta = 0){
		printf("phuong trinh co nghiem kep: %.2f", -b/(2 * a));
	}else {
		printf("phuong trinh co 2 nghiem phan biet x1 = %.2f, x2 = %.2f", (-b + sqrt(delta))/(2 * a), -(b - sqrt(delta))/(2 * a));
	}
}
