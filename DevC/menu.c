#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int number; char choice;
Label3:
printf("+-------------------------------------------------------+");
	printf("\n|1.Input|2. Sort|3.Analize|4.Find|5.Save|6.Open|7.Exit|\n");
	printf("+-------------------------------------------------------+\n");
	printf("nhap so: "); scanf("%d", &number);
	switch (number){
		case 1:	goto Label2;
				break;
		case 2:goto Label2;
				break;
		case 3: goto Label2;
				break;
		case 4:goto Label2;
				break;
		case 5:goto Label2;
				break;
		case 6:goto Label2;
				break;
		case 7:break;
			
	}
	Label2:
	printf("Do you want to continue ?\n");
			printf("Press: ");	choice = getchar();
    				while (choice == '\n') {
        			choice = getchar();
    				} 
			switch(choice){
				case 'y':
				case 'Y': 
				goto Label3;
				break;
				case 'n':
				case 'N': 
				return 0;
				break;
					
				case 'c': 
				case 'C': 
				system("cls");
				goto Label3;
				break;
			}
	return 0;
}

