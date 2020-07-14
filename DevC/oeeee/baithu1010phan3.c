#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	typedef struct{
		int yard;
		int inches;
		int feet;
	}length;
	
int main(){
	int i,j;
	float temp;
	length no[5];
	for(i = 0;i<5;i++){
		printf("Nhap length no[%d]: ",i+1);
		scanf("%d",&no[i]);
	}
	for(i=0;i<5;i++){
		for(j = 0; j < 5-i; j++){
			if(no[j].yard > no[j+1].yard){
				temp = no[j].yard;
				no[j].yard = no[j+1].yard;
				no[j+1].yard = temp;
			}
		}
	}
	for( i = 0; i < 5; i++){
		no[i].inches = no[i].yard*36;
		no[i].feet = no[i].yard*3;
	}
	for(j = 0; j <5; j++){
		printf("%d yard = %d feet = %d inches\n", no[j].yard, no[j].feet, no[j].inches);
	}
	return 0;
}
