#include <stdio.h>
#include <stdlib.h>

main()  
{  
int i,j,k,l,n;  
 
printf("Nhap pham vi: ");  
scanf("%d",&n);  
for(i=1;i<=n;i++)  
{  
for(j=1;j<=n-i;j++)  
{  
printf(" ");  
}  
for(k=1;k<=i;k++)  
{  
printf("%d",k);  
}  
  
printf("\n");  
} 

printf("\n\n===========================\n");
printf("VietJack chuc cac ban hoc tot!"); 
getch();  
}  
