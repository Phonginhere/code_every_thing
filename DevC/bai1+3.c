#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 5 % 2;
	float b = 5 /2;
	long c =  1000 % 625;
	double d = 123000/ 2626;
	printf("ket qua la: %d, ket qua la: %.1f, ket qua la %d, ket qua la: %.0f", a, b, c, d);
	return 0;
}
