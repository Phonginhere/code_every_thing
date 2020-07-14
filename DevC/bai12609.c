#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char *name;
	name = (char *)malloc(50 * sizeof(char));
	printf("Input name: "); gets(name);
	char *startPointer, *endPointer; 
  
    endPointer = name; 
    while (*endPointer == '\0') { 
        ++endPointer; 
    } 
    --endPointer; 
    
    bool isPalindrome = true;
    for (startPointer = name; endPointer >= startPointer;) { 
        if (*endPointer == *startPointer) { 
            --endPointer; 
            startPointer++; 
        } 
        else {
            isPalindrome = false;
            break; 
        }
    } 
  
    if (isPalindrome == true){
        printf("%s is Palindrome", name); 
    }         
    else {
        printf("%s is NOT a Palindrome", name); 
    }
    
	return 0;
        
}
