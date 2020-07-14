#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char mang[5][10];
	int i, j;
	for(i = 0; i < 5; i++){
        printf("Nhap chuoi %d :", i + 1); 
		scanf("%s", mang[i]);
	}
    
	for (i = 0; i < 4; i++){
    	for (j = i; j < 5; j++){
    		 if(strcmp(mang[i], mang[j]) > 0){
                char temp[10];
                strcpy(temp, mang[i]);
                strcpy(mang[i], mang[j]);
                strcpy(mang[j], temp);
		}
	}
}
    for(i = 0; i < 5; i++){
        printf("Phan tu %d la: %s\n", i+1, mang[i]);
    }  
    return 0;
}
	
