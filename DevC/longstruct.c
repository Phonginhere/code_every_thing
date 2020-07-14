#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Result{
	int math;
	int physical;
	int chemistry;
};
struct Student{
	char name [25];
	char province [25];
	int birth_year;
	struct Result;
};
int N;
struct Student* input(){
	int i;
	printf("Please input how many students in there: "); scanf("%d", &N);
	struct Student *student = (struct Student *)malloc(N * sizeof(struct Student));
	struct Result* result = (struct Result *)malloc(N * sizeof(struct Result));
	for (i = 0; i < N; i++){
INPUT_ONE:printf("Please input Student[%d]", i+1);
		printf("\nName: "); scanf("%s", (*(student+i)).name);
		printf("Province: "); scanf("%s", (*(student+i)).province);
		printf("Birth year: "); scanf("%d", &(*(student+i)).birth_year);
		 if((*(student+i)).birth_year > 2001 || (*(student+i)).birth_year < 1974) {
            printf("Year must be <= 2001 or >= 1974 \n");
            printf("Please re-enter your birth year\n");
            goto INPUT_ONE;
        }
		printf("math: "); scanf("%d", &(*(result+i)).math);
		printf("physical: "); scanf("%d", &(*(result+i)).physical);
		printf("chemistry: "); scanf("%d", &(*(result+i)).chemistry);
		if((*(result+i)).math < 0 || (*(result+i)).physical > 10) {
            printf("Mark must be >= 0 or <= 10 \n");
            printf("Please re-enter your mark\n");
            goto INPUT_ONE;
        }
    
	}
return student;
}

int main(int argc, char *argv[]) { 
	struct Student* student = NULL;
	char choice; int number;
	Label3:
	printf("+-------------------------------------------------------+");
	printf("\n|1.Input|2. Sort|3.Analize|4.Find|5.Save|6.Open|7.Exit|\n");
	printf("+-------------------------------------------------------+\n");
	printf("nhap so: "); scanf("%d", &number);
	switch (number){
		case 1:	student = input(); 
				goto Label2;
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
