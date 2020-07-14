#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	int main(int argc, char *argv[]) {
	char i; //khai bai bien i kieu character
	for( ; ; ) {
		//Vong lap vo tan(chay mai)
		printf("This will go on and on\n");
		i = getchar();
		if(i == 'X' || i == 'x'){
			//Neu go chua X hoac chu x thi thoat khoi vong for
			break;//Thoai khoi vong for
		}
	}
	return 0;
}
