#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float *d, *r, *dientich, *chuvi;
		d = (float *)malloc(1 * sizeof(float));
		dientich = (float *)malloc(1 * sizeof(float));
		chuvi = (float *)malloc(1 * sizeof(float));
		printf("nhap d: "); scanf("%f", d);
		*chuvi = *d * PI;
		printf("chu vi cua hinh tron la: %f", *chuvi);
		r = (float *)malloc(1 * sizeof(float));
		printf("\nnhap r: "); scanf("%f", r);
		*dientich = pow(2, *r) * PI;
		printf("dien tich cua hinh tron la: %f", *dientich);
	return 0;
} 


