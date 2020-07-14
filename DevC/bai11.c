#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		int age;
	printf("nhap tuoi cua ban: ");
	scanf("%d", &age);
	if (age == 15){
		printf("du tuoi nhap hoc vao 10");
	} else {
		printf("khong du tuoi nhap hoc vao 10");
	}
	return 0;
}

