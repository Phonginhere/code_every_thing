#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float toan; printf("nhap diem toan: "); scanf("%f", &toan);
	float ly; printf("nhap diem ly: "); scanf("%f", &ly);
	float hoa; printf("nhap diem hoa: "); scanf("%f", &hoa);
	float diemtong; 
	diemtong = toan + ly + hoa;
	if (diemtong >= 15) {
		printf ("\nDau");
		if ( toan >= 5 && ly >=5 && hoa >= 5){
			printf ("\nHoc deu cac mon");
		}else if (toan >= 4 && ly >= 4 && hoa >= 4){
			printf("\nHoc chua deu cac mon");
			
		} 
	} else {
		printf("\nThi Hong");
	}
	return 0;
}
