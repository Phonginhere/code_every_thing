#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i = 0;
	while (i <= 100) {
		if (i % 2 == 0) {
			printf ("\n so chan: %d", i);
		} else{
			printf("\nso le: %d", i);
		}
		i++;
	}
	return 0;
}
