//lenh goto dung de di chuyen sang mot vi tri dong lenh ma ban muon
// VD: goto(ABC); ABC:printf("bcd"); nghia la chuyen sang lenh tu ABC cua goto nay sang ABC kia
// TH ko the su dung duoc lenh goto: ko the nhay tu vi tri ben ngoai vao trong
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a;
	NHAP:printf("nhap a: "); scanf("%d", &a);
	if(a != -1) {
		goto NHAP;
	}
	return 0;
}
