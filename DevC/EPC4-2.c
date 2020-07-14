#include<stdio.h>
 
int main(){
	/*
 int Size, i, a[10];
 int Even_Sum = 0, Odd_Sum = 0;
 
 printf("\n Nhap bao nhieu so: ");
 scanf("%d", &Size);
 
 printf("\nNhap cac so\n");
 for(i = 0; i < Size; i++)
 {
      scanf("%d", &a[i]);
 }
  
 for(i = 0; i < Size; i ++)
 {
   if(a[i] % 2 == 0)
   {
 	Even_Sum = Even_Sum + a[i];
   }
   else
   {
 	Odd_Sum = Odd_Sum + a[i];
   }
 }
  
 printf("\n Tong cac so chan = %d ", Even_Sum);
 printf("\n Tong cac so le = %d ", Odd_Sum);
 */
 int a, b, c;
 printf("nhap a: "); scanf("%d", &a);
 printf("nhap b: "); scanf("%d", &b);
 c = a * b;
 if(c > 1000){
 	printf("tich %d lon hon 1000", c);
 }
 return 0;
 
}
