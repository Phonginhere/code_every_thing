#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a, b, c, d, e, f;
Label1:printf("\nnhap diem toan: "); scanf("%f", &a);
	printf("nhap diem ly: "); scanf("%f", &b);
	printf("nhap diem hoa: "); scanf("%f", &c);
	printf("nhap diem sinh hoc: "); scanf("%f", &d);
	if (a > 10 || a < 0){
		printf("nhap sai, xin moi nhap lai");
		printf("\n--------------------------------------");
		goto Label1;
	} else if (b > 10 || b < 0 ){
		printf("nhap sai, xin moi nhap lai");
		printf("\n--------------------------------------");
		goto Label1;
	} else if (c > 10 || c < 0 ){
		printf("nhap sai, xin moi nhap lai");
		printf("\n--------------------------------------");
		goto Label1;
	} else if (d > 10 || d < 0 ){
		printf("nhap sai, xin moi nhap lai");
		printf("\n--------------------------------------");
		goto Label1;
	}
	e = (a + b + c + d) / 4; f = a + b + c + d;
	printf("trung binh cac mon %f", e);
	printf("\ntong diem cac mon %f", f);
	return 0;
}
