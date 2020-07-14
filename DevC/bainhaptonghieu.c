#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a;
	float b, c, d, e; 
	char choice;
	printf("nhap so thu 1: "); scanf("%f", &b);
	printf("nhap so thu 2: "); scanf("%f", &c);
Label1:printf("\n+---------------------------------+");
	printf("\n|1.Tinh tong|2.Tinh Hieu|3.KetThuc|");
	printf("\n+---------------------------------+");
	printf("\nNhap so: "); scanf("%d", &a);
	switch(a){
		case 1:	
				d = b + c;
				printf("\n%f + %f = %f", b, c, d);
				goto LABEL2;
				break;
		case 2: d = b - c;
				e = c - b;
				printf("\n%f - %f = %f", b, c, d);
				printf("\n%f - %f = %f", c, b, e);
				goto LABEL2;
				break;
		default: goto Label1;
					break;
	}
	LABEL2:
    printf("\nDo you want to continue ?\n");
    printf("- Yes, I do. (press 'c', 'C')\n");
    printf("- No, I don’t. (press 'k', 'K')\n");
    printf("Your choice: ");
    choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch (choice) {
        case 'c':
        case 'C':
            goto Label1;
            break;
        case 'k':
        case 'K':
            return 0;
            break;
        default:
            goto LABEL2;
            break;
    }
	return 0;
}
