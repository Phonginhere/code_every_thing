#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char lang;
	printf("nhap ngon ngu: ");
	scanf("%s", &lang);
	switch(lang) 
	{
		case 'c': 
		case 'C': printf("\nC, C#, C++"); break;
		case 'ph':
		case 'PH': printf("\nPHP"); break;
		case 'j':
		case 'J': printf("\nJava"); break;
		case 'py':
		case 'PY': printf("\nPython"); break;
		case 'r':
		case 'R': printf("\nRuby"); break;
		
		default: printf("\nKo phai ngon ngu lap trinh da hoc"); break;
	}
	getchar();
}
