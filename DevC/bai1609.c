#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 int a, x;
	printf("nhap so: "); scanf("%d", &a);
	for(x = 1; x <= a; x++){
			printf("%d, ", x);
	}	
	return 0;
}
