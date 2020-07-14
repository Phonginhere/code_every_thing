#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	char fileName[250];
    printf("This is the content of the file test.txt. \n");
    printf("Input a sentence for the file : "); scanf("%s", fileName);
    FILE* file = fopen(fileName/test.txt, "wb"); 
    if(file == NULL){
        printf("Cannot save file %s\n", fileName);
    } else{
        fwrite(mobile, sizeof(struct Mobile *), N, file);
        fclose(file);
        printf("Expected Output :\n");
        printf("The file test.txt created successfully...!!");
    }
    */
     	FILE * fptr;
	int i,n;
  	char str[100];
  	char fname[20]="test.txt";
  	char str1;
  
    printf("Test Data : :\n"); 
	printf("Input the number of lines to be written : "); scanf("%d", &n);
	printf("\n :: The lines are ::\n");
	fptr = fopen (fname,"w"); 
	for(i = 0; i < n+1;i++)
		{
		fgets(str, sizeof str, stdin);
		fputs(str, fptr);
		}
  	fclose (fptr);
	fptr = fopen (fname, "r");  
	printf("\n The content of the file %s is  :\n",fname);
	str1 = fgetc(fptr);
	while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(fptr);
		}
    printf("\n\n");
    fclose (fptr);
	return 0;
}
