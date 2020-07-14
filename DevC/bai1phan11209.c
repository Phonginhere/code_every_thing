#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hour;
	float totalsalary;
	float extra;
	float salaryperhour;
	printf("nhap gio: ");
	scanf("%f", &hour);
	printf("nhap so tien/gio: ");
	scanf("%f", &salaryperhour);	
	if (hour <= 40 ) {
		totalsalary = salaryperhour * hour;
	} else {
		extra = (hour - 40) * salaryperhour * 1.5;
		totalsalary = 40 * salaryperhour + extra;
		printf("%f", totalsalary);
	}
	return 0;
}
