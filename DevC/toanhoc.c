#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double sum(int n) 
{ 
  double i, s = 0.0; 
  for (i = 1; i <= n; i++) 
      s = s *	  i; 
  return s; 
} 
int main(int argc, char *argv[]) {
	int n = 5;
	printf("Sum is %f", sum(n)); 
	return 0;
}
