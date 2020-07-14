#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char color;
	printf("nhap mau: ");
	scanf("%s", &color);
	switch(color)
	{
		case 'r': 
		case 'R': printf("RED\n"); break;
		case 'g': 
		case 'G': printf("GREEN\n"); break;
		case 'b': 
		case 'B': printf("BLUE\n"); break;
		
		default: printf("BLACK\n");
	}
	getchar();
}

