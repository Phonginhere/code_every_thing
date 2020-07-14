#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//Swap 2 integers
	int x = 10;
	int y = 20;
	int temp;
	printf("Before swap:\n");
	printf("x = %d, y = %d", x, y);
	temp = x;
	x = y;
	y = temp;
	printf("\nAfter swap: \n"); printf("x = %d, y = %d", x, y);
	//Example2: 
	char name1[50];
	char name2[50];
	char name [50];
	strcpy(name1, "Cam"); //string copy = strcpy
	strcpy(name2, "Vang");
	strcpy(name, "Trang");
	printf("\nname1 = %s, name = %s, name2 = %s", name1, name, name2);
	char strtemp[50];
	strcpy(strtemp, name1);
	strcpy(name1, name2);
	strcpy(name2, strtemp);
	printf("\nname1 = nuoc cam %s, name = %s, name2 = nuoc Vang %s", name1,name, name2);
	return 0;
}
