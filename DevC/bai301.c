#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    char fileName[250];
    printf("Open file and display the list: \n");
    printf("File name: "); scanf("%s", fileName);
    FILE *file = fopen(fileName,"rb"); 
    if (!file) {
        printf("Cannot open file %s\n", fileName);
    } else {
        fread(mobile, sizeof(struct Mobile), N, file);
        display(mobile);
        fclose(file);
    }
	return 0;
}
