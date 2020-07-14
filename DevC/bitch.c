#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	FILE *fp;
	char file;
	printf("nhap ten file de mo"); scanf("%s", &file);
	if(file = 'file.txt'){
		fp= fopen ("file.txt", "w");
		fputs("FUCK \n", fp);
	}else{
		printf("error");
	}
	fclose(fp);
	return 0;
}
