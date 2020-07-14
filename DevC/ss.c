#include <stdio.h>
#include <stdlib.h>
int main (){
   float x;
   int i = 0;
   float tong, giatritrungbinh;
   tong = 0;
   do{
   	printf("Nhap gia tri x: "); scanf("%f", &x);
   	if (x == -1) {
   		break;
	   }
		tong = tong + x;
		i++;
   }while (x != -1);
   giatritrungbinh = tong / i;
   printf("Gia tri trung binh = %0.2f\n", giatritrungbinh);
   return 0;
}
