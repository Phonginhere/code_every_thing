#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int sotruoc = -100; int sosau = 0;
do {
	printf("nhap 1 so"); scanf("%d", sosau);
	if (sosau > sotruoc) {
		printf("so sau");
	}
	sotruoc = sosau;
} while (sosau == 1 || sosau == 0);
 return 0;
}
