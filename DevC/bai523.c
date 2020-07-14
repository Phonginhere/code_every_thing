#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int arr[10], FreqArr[10], i, j, Count, Size;
	printf("Test Data :\n");
	printf("\nInput the number of elements to be stored in the array :   ");
	scanf("%d", &Size);
	printf("\nInput %d elements in the array :", Size);
	printf("\n element - %d:  ", Size);
	for (i = 0; i < Size; i++)
	{
    	scanf("%d", &arr[i]);
    	FreqArr[i] = -1;
   	}     
 
	for (i = 0; i < Size; i++)
	{
		Count = 1;
		for(j = i + 1; j < Size; j++)
		{
    		if(arr[i] == arr[j])
    		{
    			Count++;
    			FreqArr[j] = 0;
    		}
    	}
    	if(FreqArr[i] != 0)
    	{
    		FreqArr[i] = Count;
		}
	}
	printf("Expected Output: \n");
 	printf("\nThe unique elements found in the array are :");
 	for (i = 0; i < Size; i++)
  	{
  		if(FreqArr[i] == 1)
  		{
  			printf("%d\t", arr[i]);
		}		
  	}	     
	return 0;
}
