#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Employee{
	char name[25];
	int age;
	char gender [20];
};
unsigned int N;
struct Employee* input(){
	struct Employee* employee = (struct Employee*)malloc(5 * sizeof(struct Employee));
	int i;
	char male, female, temp;
	printf("nhap so nguoi: "); scanf("%d", &N);
	for (i = 0; i < N; i++){
		Input1:
	printf("nguoi thu [%d]\n", i+1);
	printf("nhap ten: "); scanf("%s", (*(employee+i)).name);
	printf("nhap tuoi: "); scanf("%d", &(*(employee+i)).age);
	printf("nhap gioi tinh(M/F): "); scanf("%s", (*(employee+i)).gender);
	if((*(employee+i)).age < 18 || (*(employee+i)).age >= 22){
		printf("tuoi tu 18 cho den 22\n");
		printf("hay nhap lai\n");
		goto Input1;
	} 
}
	return employee;
}
void display(struct Employee* employee){
	int i, numberOfEmployee;
	printf("|-----------------------------------|\n");
	printf("|1.Name            |2.Age |3.Gender |\n");
	numberOfEmployee = 0;
	for(i = 0; i < N; i++){
		printf("|%-18s", (*(employee+i)).name);
		printf("|%-6d", (*(employee+i)).age);
		printf("|%-9s|\n", (*(employee+i)).gender);
		numberOfEmployee++;
	}
	printf("|-----------------------------------|\n");
	printf("%d Employee", numberOfEmployee); 
}
void sort(struct Employee* employee){
	int i,j;
	for(i = 0; i < N - 1; i++){
		for(j = i + 1; j < N; j++){
			if (strcmp((*(employee+i)).name,(*(employee+j)).name) > 0){
				struct Employee temp;
				temp = *(employee +i);
				*(employee +i) = *(employee +j);
				*(employee +j) = temp;
			}
		}
	}
	printf("sort finished\n");
	display(employee);
} 
/*
void analyze(struct Employee* employee){
	char age[N][250];
		int i,j;
	for(i = 0; i < N; i++){
		strcpy(age[i], (*(employee+i)).age);
}
	for(i = 0; i < N-1; i++){
		for(j = i + 1; j < N; j++){
			if(strcmp(age[i], age[j]) > 0){
				char temp[150];
			strcpy(temp, age[i]);
			strcpy(age[i], age[j]);
			strcpy(age[j], temp);
			}
		}
	}
	printf("Ket qua:\n");
	char ageName[150];
	int count = 0;
	for (i = 0; i < N; i++){
		if(i == 0){
			strcpy(ageName, age[i]);
			count++;
		} else if(strcmp(age[i], ageName) != 0){
			printf("+There are %d age from %d", count, ageName);
			strcpy(ageName, age[i]);
			count = 1;
		} else if(strcmp(age[i], ageName) == 0){
			count++;
		}
	}
	if(N > 0){
		printf("there are %d age from %d\n", count, ageName);
	}
}
*/
void analyze (struct Employee* employee){
	char genders[N][100];
	int i,j;
	for(i=0;i<N;i++){
		strcpy(genders[i],(employee+i)->gender);
	}
	for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			if(strcmp(genders[i], genders[j])> 0){
			char temp[200];
			strcpy(temp, genders[i]);
			strcpy(genders[i],genders[j]);
			strcpy(genders[j],temp);	
			}	
		}
	}	
	printf("Result:");
	char EmployeeGender[200];
	int count=0;
	for(i=0;i<N;i++){
		if(i==0){
			strcpy(EmployeeGender, genders[i]);
			count++;	
		}else if(strcmp(genders[i],EmployeeGender)!=0){
			printf("There are %d perdson gender by %s\n",count, EmployeeGender);
			strcpy(EmployeeGender,genders[i]);
			count = 1;
		}else if(strcmp(genders[i],EmployeeGender)==0){
			count++;
		}
	}
	if(N>0){
		printf("There are %d perdson gender by %s\n",count, EmployeeGender);
	}	
}
void find(struct Employee* employee){
	printf(" Find Employee");
	struct Employee *employeeFind = (struct Employee *)malloc(N * sizeof(struct Employee));
	struct Employee *prt;
	float maxAge, minAge;
	char gender[10];
	printf("Gender: ");scanf("%s",gender);
	printf("Enter min Age: "); scanf("%f",&minAge);
	printf("Enter max Age: "); scanf("%f",&maxAge);
	prt = employeeFind;
	int i = 0;
	for(i = 0; i < N; i++) {
		if(strcmp((employee+i)->gender, gender ) == 0 &&
		 (employee + i)->age >= minAge && (employee+i)->age <= maxAge ) {
			*prt = *(employee + i);
			prt++;
		}
	}
	printf("Search result : \n");
	display(employeeFind);
}
void save(struct Employee* employee){
	char fileName[500];
	printf("Enter file name :");scanf("%s",fileName);
	FILE* file = fopen(fileName,"wb");
	if(file == NULL){
		printf("Cannot open file %s\n",fileName);
	}else{
		fwrite(employee,sizeof(struct Employee*),N,file);
		fclose(file);
		printf("Data is saved succesfully \n");
	}
}
void openFile(struct Employee* employee){
	char fileName[500];
	printf("Enter file name to open :");scanf("%s",fileName);
	FILE* file = fopen(fileName,"rb");
	if(!file){
		printf("Cannot open fie %s\n",fileName);
	}else{
		fread(employee,sizeof(struct Employee),N,file);
		display(employee);
		fclose(file);
	}
}
int main(int argc, char *argv[]) {
Label1:	printf("+------------------------------------------------------------------------+\n");
	printf("| EMPLOYEE MANAGEMENT PROGRAM |\n");
	printf("+------------------------------------------------------------------------+\n");
	printf("|1. Input |2. Sort |3. Analyze |4. Find |5. Save |6. Open |7. Exit |\n");
	printf("+------------------------------------------------------------------------+\n");
	unsigned int select;
	printf("nhap so: "); scanf("%d", &select); 
	struct Employee* employee;
	switch(select){
		case 1: employee = input();
				goto Label2;
				break;
		case 2: sort(employee);
				goto Label2;
				break;
		case 3: analyze(employee);
				goto Label2;
				break;
		case 4: find(employee);
				goto Label2;
				break;
		case 5: save(employee);
				goto Label2;
				break;
		case 6: openFile(employee);
				goto Label2;
				break;
		case 7: break;
		default: goto Label1;
				break;
	}
	Label2: 
		printf("Do you want to continue: \n");
		printf("-Yes, I do/(Press 'Y' or 'y')\n");
		printf("-No, I don't/ Press 'N' or 'n'\n");
		printf("-Clear the screen/ Press 'C' or 'c'\n");
		printf("Your choice: ");
		select = getchar();
		while (select == '\n'){
			select = getchar();
		}
		switch (select){
			case 'Y':
			case 'y': goto Label1;
					break;
			case 'N':
			case 'n': break;
			case 'C':
			case 'c': system("cls"); 
					goto Label1;
			default: goto Label2;
		}
	return 0;
}
