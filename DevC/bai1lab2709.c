#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int *N;
	int *numbers; 
	int i, max, min;
	N = (int *)malloc(1 * sizeof(int));
	printf("Nhap N = "); scanf("%d", N);
	//Allocate for array:
	numbers = (int *)malloc(*N * sizeof(int));
	for(i = 0; i < *N; i++){
		printf("nhap phan tu %d : ", i); scanf("%d", numbers);
		if(i == 0) {
			min = *numbers;
			max = *numbers;
		} else{
			if(*numbers > max) {
				max = *numbers;
			}
			if(*numbers < min) {
				min = *numbers;
			}
		}
		numbers++;
	}
	printf("Max = %d, min = %d", max, min);
	return 0;
}
