#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long seconds, hours, minutes, remainSeconds;
    do {
        printf("Enter seconds: ");
        scanf("%ld", &seconds);
        hours = seconds / 3600;
        minutes = (seconds % 3600)/60;
        remainSeconds = seconds - 3600 * hours - 60 * minutes;
        printf("%ld: %ld: %ld\n", hours, minutes, remainSeconds);
    } while(seconds < 0 || seconds > 86399);
	return 0;
}
