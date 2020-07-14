#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int N, i; 
	char name [50], quan [25], team, tuoi, luong;
	printf("nhap so nguoi: "); scanf("%d", &N);
	for(i = 0; i < N; i++){
		printf("nguoi thu [%d]", i+1);
		printf("\nnhap ten: "); scanf("%s", name);
		printf("nhap quan: "); scanf("%s", quan);
		printf("nhap to: "); scanf("%d", &team);
		printf("nhap tuoi: "); scanf("%d", &tuoi);
		printf("nhap luong: "); scanf("%d", &luong);
		printf("----------------------------------\n");
	}
	if (quan == 3 && tuoi < 30 && luong > 500000){
		for (i = 0; i < N; i++){
		
		printf("nguoi thu [%d]", i+1);
		printf("\nnhap ten: %s ", name+i); 
		printf("nhap quan: %s", quan+i);
		printf("nhap to: %d", team+i);
		printf("nhap tuoi: %d", tuoi+i); 
		printf("nhap luong: %d", luong+i); 
		printf("\n----------------------------------");
		}
	}
	return 0;
}
