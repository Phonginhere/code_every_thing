#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1, num2, i, total;
    printf("Nhap so thu nhat: "); scanf("%d", &num1);
    printf("Nhap so thu hai: "); scanf("%d", &num2);
    total = 0;
    for(i = num1; i <= num2; i++) {
        if(i % 2 != 0) {
            total += i;
        }
    }
    printf("Tong cac so le = %d\n", total);
	return 0;
}
