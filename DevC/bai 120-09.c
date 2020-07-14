#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	//Dau vao, ten va tuoi
	char name[100];//maximum 100 characters
	unsigned int age;//unsigned = positive(>0)
	int i;
	printf("Nhap ten:"); gets(name);//gets = GET a String from your Keyboard
	printf("Nhap tuoi: "); scanf("%d", &age);
	for(i = 0; i < age;i++) {
		printf("%d - %s\n", i+1, name);//%s = string
	}
	return 0;
}
