#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char*argv[]){
 	int month, year;
 	printf("nhap mot so tu 1 den 12: "); scanf("%d",&month);
 	printf("Nhap nam: ", &year); scanf("%d", &year);
 	switch(month) {
 		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("\nthang %d co 31 ngay", month); 
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("\nthang %d co 30 ngay", month);
			break;
		case 2:
			if(year % 4 == 0){
				printf("\nthang %d co 29 ngay", month);
			} else {
				printf("\nthang %d co 28 ngay", month);
			}
			
			break;
		default:
			printf("ko hop le");
			break;
			
	}
	return 0;
 }
