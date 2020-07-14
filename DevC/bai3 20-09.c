#include <stdio.h>

int main(){
	int N, i, j;
	printf("nhap so: "); scanf("%d", &N);
	for(i = N; j <= 10; j++)
        {
            printf("\n%d x %d = %d", i, j, i*j);
        }
    return 0;
}
