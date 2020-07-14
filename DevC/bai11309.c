#include <stdio.h>
#include <stdlib.h>

int main(){
	float x;
	float a;
	float b;
	printf("nhap so thuc duong");
	scanf("%f", &x);
	do 
	{
		a = x - 2;
		b = x - 4;
		printf("\ngia tri cua a la : %.0f, %.0f, %.0f",x, a, b);
	} while (x < 3 );
	return 0;
}
