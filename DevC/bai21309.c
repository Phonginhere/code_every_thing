#include <stdio.h>
#include <stdlib.h>
int main (){
   int a = 100;

   /* vong lap do...while */
   do
   {
       printf("Gia tri cua a la: %d\n", a);
       a = a - 5;
   }while( a > 0 );
   return 0;
}
