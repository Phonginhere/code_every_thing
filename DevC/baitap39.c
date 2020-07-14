#include <stdio.h>
#include <stdlib.h>

int main(){
		char ch;
		do{
		printf("Nhap 1 so tu 1 -> 5: "); ch = getchar();
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
