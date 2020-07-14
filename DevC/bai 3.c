#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main() {

    int r;
	int PI = 3.1415;

    float chuvi, dientich;

    printf("Nhap ban kinh r:");

    scanf("%d", &r);

    chuvi = 2*PI*r;

    dientich = PI*r*r;

    printf("Chu vi hinh tron la: %f\n", chuvi);

    printf("Dien tich hinh tron la: %f", dientich);

    return 0;

}


