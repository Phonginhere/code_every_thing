#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
   int i,j,spc,rows,k;
   printf("Input number of rows : ");
   scanf("%d",&rows);
   spc=rows+4-1;
   for(i=1;i<=rows;i++)
   {
         for(k=spc;k>=1;k--)
            {
              printf(" ");
            }
                      
	   for(j=1;j<=i;j++)
	   printf("%d ",i);
	printf("\n");
    spc--;
   }
	return 0;
}
