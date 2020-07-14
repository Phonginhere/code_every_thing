#include <stdio.h>
 
int main()
{
    int x = 1; // make x >= 0 is true -> while will run
 
    while (x >= 0)
    {
        printf("Nhap vao mot so : ");
        scanf("%d", &x);
    }
 
    printf("Ok, Program is finish!\n");
 
    return 0;
}
