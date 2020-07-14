#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int count = 0;
	while(count < 100){
	printf("This goes on forever, HELP!!!\n");
	count+=10;
	printf("\t%d", count);
	count-=10;
	printf("\t%d”, count");
	printf("\nCtrl-C will help");
}
	return 0;
}
//khi them 10 va tru 10, no van se hoat dong lien tuc cho den khi minh nhan to hop ctrl c
//muc dich cua bai nay la van de lap lai cua dong lenh in cho 2 lenh +- 10
