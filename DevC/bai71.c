#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	char s[200];
    int count = 0, i;
 
    printf("Nh?p tên b?n:\n");
    scanf("%[^\n]s", s);
    printf("hi?n th? ra màn hình: %s\n", s);
    for (i = 0;s[i] != '\0';i++)
    {
        if (s[i] == ' ' && s[i+1] != ' ')
            count++;    
    }
    printf("Number of words in given string are: %d\n", count + 1);
	return 0;
}
