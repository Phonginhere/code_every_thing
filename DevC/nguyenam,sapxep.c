#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	 int i, vCount = 0, cCount = 0;  
   char str[100];
   printf("nhap chu cai: "); scanf("%s", str);
   for(i = 0; i < strlen(str); i++){  
       str[i] = tolower(str[i]);  
       if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {  
           //Increments the vowel counter  
            vCount++;  
        }   
   }  
   printf("Number of vowels : %d\n", vCount);  
    */
     char name[10][8], tname[10][8], temp[8];
        int i, j, n;
 		
        printf("Nhap so can go: \n");
        scanf("%d", &n);
        printf("Nhap %d ten \n", n);
 
        for (i = 0; i < n; i++) 
        {
            scanf("%s", name[i]);
            strcpy(tname[i], name[i]);
        }
 
        for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(name[i], name[j]) > 0) 
                {
                    strcpy(temp, name[i]);
                    strcpy(name[i], name[j]);
                    strcpy(name[j], temp);
                }
            }
        }
 
        printf("\n----------------------------------------\n");
        printf("Input NamestSorted names\n");
        printf("------------------------------------------\n");
 
        for (i = 0; i < n; i++) 
        {
            printf("%s\t\t%s\n", tname[i], name[i]);
        }
 
        printf("------------------------------------------\n");
 

	return 0;
}
