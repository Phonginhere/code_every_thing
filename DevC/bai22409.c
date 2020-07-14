#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
	char name[100];
	int i;
	int numberOfVowels, numberOfConsonants;
	numberOfVowels = 0;
	numberOfConsonants = 0;
	printf("Enter a string : "); gets(name);
	//strlen = string's length
	for(i = 0; i < strlen(name); i++) {
		if(name[i] == 'a' || name[i] == 'A'  ||
			name[i] == 'e' || name[i] == 'E' ||
			name[i] == 'i' || name[i] == 'I' ||
			name[i] == 'o'|| name[i] == 'O' ||
			name[i] == 'u' || name[i] == 'U'){
			numberOfVowels++;
			printf("vowel: %c\n", name[i]);
		} else {
			numberOfConsonants++;
			printf("Consonant: %c\n", name[i]);
		}
	}
	printf("Number of vowels: %d, \nnumber of consonants : %d\n", 
				numberOfVowels,numberOfConsonants);
	return 0;
}
