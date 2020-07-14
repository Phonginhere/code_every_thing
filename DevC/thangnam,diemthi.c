#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	int month, year;
	printf("nhap thang: "); scanf("%d", &month);
	printf("nhap nam: "); scanf("%d", &year);
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: printf("\nthang %d co 31 ngay", month);
									break; 
		case 4:
		case 6:
		case 9:
		case 11: printf("\nthang %d co 30 ngay", month);
						break; 
		case 2: if (year % 4 == 0){
			printf("\nthang %d co 29 ngay", month);
			break;
		} else {
			printf("\nthang %d co 28 ngay", month);
			break;
		}
	}
	*/
	float math, phy, chem, total;
	printf("nhap so diem toan: "); scanf("%f", &math);
	printf("nhap so diem ly: "); scanf("%f", &phy);
	printf("nhap so diem hoa: "); scanf("%f", &chem);
	total = math + phy + chem;
	printf("tong diem la %f", total);
	if (total >= 15 && math > 4 && phy > 4 && chem > 4){
		
		printf("\ndau");
	} else if (total >= 15 && math > 5 && phy > 5 && chem > 5){
		printf("\nhoc deu cac mon");
	} else if (total < 15 && math < 4 || phy < 4 || chem < 4){
		printf("\nHoc chua deu cac mon");
	} else {
		printf("Thi hong");
	}
	return 0;
}
