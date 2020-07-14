#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct length{
	float cm; 
	float kilometers; 
	float yards;
	float feet; 
	float inches;
};

int main(int argc, char *argv[]) {
	float i, j;
	float cm1;
	float cm2;
	float cm3;
	float cm4;
	float temp;
	struct length * dodai;
				dodai = (struct length *)
					malloc(sizeof(struct dodai *));
		printf("Enter length (cm): ");
		scanf("%d", &(*dodai).cm);
	 
	(*dodai).feet = 0.032808;
	(*dodai).inches = 0.393701;
	(*dodai).kilometers == 0.00001;
	(*dodai).yards == 0.010936;
	
	cm1 == (*dodai).cm * (*dodai).feet;
	cm2 == (*dodai).cm * (*dodai).inches;
	cm3 == (*dodai).cm * (*dodai).kilometers;
	cm4 == (*dodai).cm * (*dodai).yards;
	printf("%f cm = %f feet\n", (*dodai).cm , cm1);
	return 0;
}
