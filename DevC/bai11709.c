#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b, c, d;
	printf("nhap a: "); scanf("%d", &a);
	printf("nhap b: "); scanf("%d", &b);
	printf("nhap c: "); scanf("%d", &c);
	printf("nhap d: "); scanf("%d", &d);
	if (a > b && a > c && a > d ) {
		printf("a la so lon nhat");
	} else if (b > a && b > c && b > d) {
		printf("b la so lon nhat\n");
	} else if ( c > a && c > b && c > d) {
		printf("c la so lon nhat\n");
	} else if (d > a && d > b && d > c) {
		printf("d la so lon nhat\n");
	} 
	return 0;
}
