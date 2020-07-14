#include <stdio.h>
#include <stdlib.h>

int main() {
	char calculation;
	printf("nhap phep tinh:"); scanf("%s", &calculation);
	switch (calculation) {
		case '*': printf("\nphep nhan"); break;
		case '/': printf("\nphep chia"); break;
		case '+': printf("\nphep cong"); break;
		case '-': printf("\nphep tru"); break;
		default: printf("\nko hop le"); break;
	}
}
