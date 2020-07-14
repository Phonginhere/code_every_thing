#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num1,num2,tong,i;
	printf("nhap num1"), scanf("%d",&num1);
	printf("nhap num2"), scanf("%d",&num2);	
	tong=0;
	for(i=num1;i<=num2;i++){
       if(i%2 != 0){
       	tong=tong+i;
       	
	   }
	} 
	printf("tong la=%d",i);
	return 0;
}
