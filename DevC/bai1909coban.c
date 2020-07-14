#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, N;
    double kq = 1;
    printf("Nhap N = "); scanf("%d", &N);
    i = 0;
    while (i < N) {
        i++;
        kq = kq * i;
    }
    printf("Giai thua cua %d la: %1.0f\n", N, kq);
	return 0;
}
