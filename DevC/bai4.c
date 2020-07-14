#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i = 2, count = 0;
	printf("nhap n = "); scanf("%d", &n);
	while(i < n - 1){
		if(n % i == 0){
			count++;
		}
		i++;
	} 
	if(count > 0){
		printf("\nKo phai la so nguyen to");
	} else {
		printf("\nLa so nguyen to");
	}
	return 0;
}
