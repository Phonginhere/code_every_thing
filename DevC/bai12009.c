#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char name[100];
	unsigned int age;
	int i;
	printf("nhap ten: "); gets(name);
	printf("nhap tuoi: "); scanf("%d", &age);
	i = 0;
	while (i < age){
		printf("%d. %s\n", i+1, name);
		i++;
	}
 	return 0;
}
