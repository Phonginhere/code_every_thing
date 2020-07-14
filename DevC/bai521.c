#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j, a, b;
    printf("Expected Output :\n");
    printf("Input hours: "); scanf("%d", &i);
    printf("Input minutes: "); scanf("%d", &j);
    a = i * 60;
    b = a + j;
    printf("Total: %d", b);
    return 0; 
}
