#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *word;
	word = (char *)malloc(50 * sizeof(char));
	printf("Enter a string : ");gets(word);
	int i,numberOfVowels,numberOfConsonants;
	numberOfVowels = 0;
	numberOfConsonants = 0;
	int length = strlen(word);
	for(i = 0; i < length; i++) {
		if(*word == 'a' || *word == 'A' ||
			*word == 'e' || *word == 'E' ||
			*word == 'i' || *word == 'I' ||
			*word == 'o' || *word == 'O' ||
			*word == 'u' || *word == 'U') {
			numberOfVowels++;
		} else {
			numberOfConsonants++;		
		}
		word++;
	}
	printf("Number of vowels : %d", numberOfVowels);
	printf("\nNumber of consonants : %d", numberOfConsonants);
	return 0;
}

