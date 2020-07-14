#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int N,i,tong_so_am,tong_so_duong,tong_so_khong,x;
tong_so_khong=0;
tong_so_duong=0;
tong_so_am=0;
printf("nhap N:"); scanf("%d",&N);
for(i=0;i<=N-1;i++){
printf("nhap x:"); scanf("%d",&x);
if(x<0) {
tong_so_am++;
} else if(x>0) {
tong_so_duong++;
} else if(x==0) {
tong_so_khong++;
}
} printf("tong so am la=%d\n",tong_so_am);
printf("tong so duong la=%d\n",tong_so_duong);
printf("tong so khong la=%d\n",tong_so_khong);
return 0;
}
