#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void sort(float *x, float length, float sortType) {
	int i, j;
	for(i = 0; i < length - 1; i++){
		for(j = i + 1; j < length; j++){
				if (*x(x + i) < *(x + j)){
					float temp;
					temp = *x(x + i);
					* (x + i) = (x + j);
					(x + j) = temp;
		}
	}
}

struct student{
	char tenhocsinh [50];
	int diem [25];
};
int main(int argc, char *argv[]) {
	int i, N;
	struct student * hocsinh;
	hocsinh = (struct student *)
		malloc(sizeof(struct student * ));
		printf("nhap 5 hoc sinh: "); scanf("%d", &N);
	nhap:for(i = 1; i <= N; i++){
	printf("nhap ten: "); scanf("%s", &(* hocsinh). tenhocsinh);
	printf("nhap diem: "); scanf("%d", &(* hocsinh). diem);
	printf("----------------------\n");
		for(i )
	}
	return 0;
}
