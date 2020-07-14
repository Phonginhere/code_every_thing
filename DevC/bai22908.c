#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		char ch;
		do{
		printf("\nNhap 1 so tu 1 -> 5: "); ch = getchar();
		switch (ch) {
			case '1': printf("lam viec A"); break;
			case '2': printf("lam viec B"); break;
			case '3': printf("lam viec C"); break;
			case '4': printf("lam viec D"); break;
			default: break;
					
		}
		getchar();
	} while (ch != '5');
	printf("ket thuc CT");	
	return 0;
}


