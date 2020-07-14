#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, N, ketqua;
	printf("nhap N:"); scanf("%d", &N);
	for(i = 1; i <= N; i++){
		ketqua *= i;
	}
	printf("ket qua la: %d", ketqua);
	return 0;
}
