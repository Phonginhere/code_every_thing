#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	int N, numbers[20],i;
	int max, min;
	printf("Enter number of integers : "); scanf("%d", &N);
	if(N > 20){
		printf("Cannot calculate");
		return 0;
	}
	for(i = 0; i < N; i++){
		printf("Enter an integer : "); scanf("%d", &numbers[i]);
	}
	//Initialize values for max, min
	max = numbers[0];
	min = numbers[0];
	//Calculate max, min
	for(i = 1; i < N; i++) {
		if(numbers[i] > max) {
			max = numbers[i];
		}
		if(numbers[i] < min){
			min = numbers[i];
		}
	}
	printf("Max is : %d, min is : %d", max, min);
	return 0;
}
