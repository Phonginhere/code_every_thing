#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 5 % 2;
	float b = 5 /2;
	long c =  1000 % 625;
	double d = 123000/ 2626;
	printf("add a la: %p, add b la: %p, add c la %p, add d la: %p", a, b, c, d);
	return 0;
}

