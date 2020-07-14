#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int so_tien_gui, lai_suat, tien_lai, laisuat, so_thang, tong_so_tien;
    printf("nhap so tien gui:"); scanf("%d", &so_tien_gui);
    printf("nhap lai suat (%):"); scanf("%d", &lai_suat);
    printf("so thang gui:"); scanf("%d", &so_thang);
    laisuat = lai_suat / 100;
    tien_lai = so_tien_gui * laisuat / 12 * so_thang;
    tong_so_tien = so_tien_gui + tien_lai;
    printf("nguoi gui se lanh: %d", tien_lai);
    printf("nguoi gui se nhan duoc ca lai lan von tien la: %d", tong_so_tien);
	return 0;
}
