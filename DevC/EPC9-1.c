#include<stdio.h>
 
int main()
{
 int N, i, a[10];
 int Positive_Count = 0, Negative_Count = 0, Zero_Count = 0;
 
 printf("\n Please Enter the Size of an Array :  ");
 scanf("%d", &N);
 
 for(i = 0; i < N; i++){
 	printf("nhap so [%d]: ", i); scanf("%d", &a);
 }
  
 for(i = 0; i < N; i ++)
 {
   if(a > 0)
   {
 	Positive_Count++;
   }
   else if(a < 0)
   {
 	Negative_Count++;
   }
   else{
   	Zero_Count++;
   }
 }
  
 printf("\n Total Number of Positive Numbers in this Array = %d ", Positive_Count);
 printf("\n Total Number of Negative Numbers in this Array = %d ", Negative_Count);
 printf("\n Total Number of Positive Numbers in this Array = %d ", Zero_Count);
 return 0;
}
