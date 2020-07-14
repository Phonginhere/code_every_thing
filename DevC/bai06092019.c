#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char ch;
	do{
		printf("\nnhap mot so tu 1 -> 7: "); ch = getchar();
		switch (ch) {
			case '1': printf("thu hai"); break;
			case '2': printf("thu ba"); break;
			case '3': printf("thu tu"); break;
			case '4': printf("thu nam"); break;
			case '5': printf("thu sau"); break;
			case '6': printf("thu bay"); break;
			case '7': printf("chu nhat"); break;
			default: break;
		}
		getchar();
	}while (ch != '8');
	printf("ket thuc chuong trinh");
	return 0;
}
