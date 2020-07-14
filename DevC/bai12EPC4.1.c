#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a, b, c, d, e, f;
Label1:printf("nhap a: "); scanf("%f", &a);
	printf("nhap b: "); scanf("%f", &b);
	if (b != 0){
	c =	a / b;
	d = a + b;
	e = a - b;
	f = a * b;
	printf("a / b = %f", c);
	printf("\na + b = %f", d);
	printf("\na - b = %f", e);
	printf("\na * b = %f", f);
	}else{
		printf("b sai nhap lai\n");
		goto Label1;
	}
	
	return 0;
}
