#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	printf("nhap so nguyen tu a: "); scanf("%d",&a);
	printf("nhap so nguyen tu b: "); scanf("%d",&b);
	printf("nhap so nguyen tu c: "); scanf("%d",&c);
	int max=a;
	if(b>max) {
		max=b;
	} 
	if(c>max){
		max=c;
		printf("diem cao nhat = %d",max);
	}
	return 0;
}
