#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j , max;
	printf("Please enter the maximum value \n"); //nhap gia tri cao nhat
	printf("for which a table can be printed: "); // cho mot bang co the in ra
	scanf("%d", &max); // phai co cai nay de nhap vao
	for(i = 0 , j = max ; i <=max ; i++, j--) { // lap lai bat dau tu i=0 cho den xet dieu kien cua j va i roi sau do tang 1 gtri cho i va giam 1 gia tri cho j
	printf("\n%d + %d = %d",i, j, i + j); // in ra man hinh cac phep cong 
	}
	return 0;
}
