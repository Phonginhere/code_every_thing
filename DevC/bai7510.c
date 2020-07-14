#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
      char mang [100];
      char ch;
      printf("nhap chuoi ki tu: "); scanf("%s", mang);
      getchar();
      printf("tim mot chu cai de tim\n"); ch = getchar();
    	int i;
		int sum = 0;
    	
		for(i = 0; mang [i] != '\0'; i++){
    	if(mang[i] == ch){
    		sum++;
		}
	}
		printf("Tong so phan tu %c la: %d", ch, sum );
      return 0;
}
