/* for la lenh lap lai
 while la lenh bieu thuc, neu dung thi vao khoi lenh, neu sai thi thoat
 for (a = 0; a <= b; a++): bat dau tu a = 0 roi den xet dieu kien a nho hon hoac bang b cuoi cung la them 1 vao bien a
 while (a != 1): neu a khac 1 thi tiep tuc con a = 1 phai nhap lai
*/
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
int main(int argc, char *argv[]) {
	int a, b;
	I: printf("nhap b: "); scanf("%d", &b);
	for(a = 0; a < b; a = a + 1)
	{
		printf("%d", b);
	} while(b <= -1){
		goto I;
	}
	return 0;
} */
	int main(int argc, char *argv[]) {
		int a, b;
		I: printf("nhap a"); scanf("%d", &b);
		while(b < 0){
			goto I;
		} for(a = 0; a <= b ; a++){
			printf("%0.d", a);
		}
	return 0;
}


