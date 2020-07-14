#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float feet;
    float inches, cm;
    printf("Enter number (cm): ");
    scanf("%f", &cm);
    
    inches = cm / 2.54;
    feet = inches / 12.0;
    printf("%0.3f centimeters is %0.1f feet\n", cm, feet);
    printf("%0.3f centimeters is %0.1f inches\n", cm, inches);
    return 0;
}
