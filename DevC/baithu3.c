#include <stdio.h>
#include <stdlib.h>

	struct Person{
	unsigned int N;
	char name[100];
	unsigned int age;
	char job[100];
	
};
int main(int argc, char *argv[]) {
	int i,x,y,z,in,h,line,o;
	unsigned int N;
		struct Person *person;
		person=(struct Person *)malloc(sizeof(struct Person *));
		FILE *pFile;
	NGU:printf("1.Input some persons\n2.Save to file\n3.Open\n4.Exit");
	x=getchar();
		
	switch(x){
		case '1':
			printf("nhap so nguoi");scanf("%d",&N);
			for(h=0; h < N;h++){
				printf("\nInput some person:");
				fscanf(stdin,"%s",(*person).name);
				printf("nhap tuoi: ");
				fscanf(stdin,"%d",&((*person).age));
				printf("nhap job: ");
				fscanf(stdin,"%s",(*person).job);
			}goto NGU;
			break;
//			A:printf("%s\n%d\n%s",(*person).name,((*person).age),(*person).job);
			
//		printf("1.Input some persons\n2.Save to file\n3.Open\n4.Exit");
//		o = getchar();
//			switch(o){
				case '2':
				    if(pFile = fopen("C:/Users/Admin/Desktop/AptechNangCao/TuanThongMinh.txt", "r+") == NULL){
					printf("Cannot open file \n\n");
					exit(1);
					}
					//printf("%s\n%d\n%s",(*person).name,((*person).age),(*person).job);
					//fputs("",pFile);
			 		fprintf(pFile,"Name= %s\n",(*person).name);
					fprintf(pFile,"Age= %d\n",(*person).age);
					fprintf(pFile,"Job= %s\n",(*person).job);
			 		fclose(pFile);
					break;
				case '3':
					pFile = fopen("F:/phong.txt","r");
					if(pFile != NULL){
					line = 0;
					char input[512];
					while(fgets(input,512,pFile)){
					line++;
					printf("%c %s",line,input);
					}
					} else{
					printf("Can not find this file");
				}
					fclose(pFile);
					break;
//			}getchar();
		}getchar();
	
	return 0;
}
