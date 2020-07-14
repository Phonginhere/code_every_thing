#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	//Initialize array
	char name[7][10];
	int i, j;
	strcpy(name[0], "George"); //strcpy = string copy
	strcpy(name[1], "Albert");
	strcpy(name[2], "Tina");
	strcpy(name[3], "Xavier");
	strcpy(name[4], "Roger");
	strcpy(name[5], "Tim");
	strcpy(name[6], "William");
	for(i = 0; i < 6; i++){
		for(j = i + 1; j < 7; j++){
			if(strcmp(name[i], name[j]) < 0) {//strcmp = string compare
				char strtemp[100];
				//swap name[i], name[j]
				strcpy(strtemp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], strtemp);
			}
		}
	}
	for(i = 0; i < 7; i++) {
		printf("%s\n", name[i]);
	}
	return 0;
}
