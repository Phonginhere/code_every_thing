// contro(pointer) trong C la mot bien ma dia chi cua no co gia tri cua bien khac VD nhu dia chi cua mot ngoi nha
// ban can phai khai bao dia chi truoc khi su dung no de luu tru bat ky gia tri nao
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a, b;
	printf("nhap a: "); scanf("%f", &a);
	printf("nhap b: "); scanf("%f", &b);
	
  	float *ptr1, *ptr2;
   	ptr1 = &a;
   	ptr2 = &b;
   	float *num;
	num = (float *)malloc(1 * sizeof(float));
   	*num = *ptr1 * *ptr2;

   	printf("tich hai so = %f", *num);
	return 0;
}
