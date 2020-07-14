#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	int dd,mm,yyyy;
   
    printf("\n + Ngay: ");
    scanf("%d",&dd);
 
    printf("\n + Thang: ");
    scanf("%d",&mm);
 
    printf("\n + Nam: ");
    scanf("%d",&yyyy);
 
 
    printf("\nNgay thang nam vua nhap la: %2d/%2d/%2d",dd,mm,yyyy%100);
    getch();
    */
    float a, b, c;
    printf("nhap a: "); scanf("%f", &a);
    b = pow(a, 2);
    c = pow(a, 3);
    printf("%f^2 = %f", a, b);
    printf("\n%f^3 = %f", a, c);
	return 0;
}
