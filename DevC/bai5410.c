#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sort(float *x, float length, float sortType) {
	int i, j;
	for(i = 0; i < length - 1; i++) {		
		for(j = i + 1; j < length; j++) {
			if(sortType == 0){//sap xep tang dan
				if(*(x + i) > *(x+j)){
					float temp;
					temp = *(x + i);	
					*(x + i) = *(x + j);	
					*(x + j) = temp;
				}	
			} else if(sortType == 1){//sap xep giam dan
				if(*(x + i) < *(x+j)){
					float temp;
					temp = *(x + i);	
					*(x + i) = *(x + j);	
					*(x + j) = temp;
				}	
			}
		}	
	}
}

int main(int argc, char *argv[]) {
	float *x;
	int N, i, max; 
	printf("Nhap so phan tu : "); scanf("%d", &N);
	x = (float *)malloc(N * sizeof(float));
	for(i = 0; i < N; i++){
		printf("Nhap x[%d] = ", i); scanf("%f", (x+i));
	}
	//int *y;
	//sortType = 0: tang dan, sortType = 1: giam dan
	sort(x, N, 1);//giam dan	
	for(i = 0; i < N; i++){
		printf("x[%d] = %f\n",i, *(x+i));
	}
	printf("\n---------------------------");
	sort(x , N, 0);
	for(i = 0; i < N; i++){
		printf("\nx[%d] = %f",i, *(x+i));
	}
	return 0;	

}
