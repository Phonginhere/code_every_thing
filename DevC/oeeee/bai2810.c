#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Person{
	char name [50];
	unsigned int age [50];
	char job [100];
};
int N;
struct Person *input(){
	printf("So thanh vien: "); scanf("%d", &N);
	struct Person *Person = (struct Person *)malloc(N * sizeof(struct Person));
	int i;
	for (i = 0; i < N; i++){
		printf("Person number %d: \n", i+1);
		printf("Nhap ten thanh vien: "); scanf("%s", (*(Person+i)).name);
		printf("Nhap tuoi thanh vien"), scanf("%s", &((*(Person+i)).age));
		printf("Nhap nghe nghiep thanh vien "); scanf("%s", (*(Person+i)).job);
	}
	return Person;
}
void save(struct Person *person){
	char fileName[100];
	char filePath[250];
	printf("nhap ten file: "); scanf("%s", fileName);
	strcat(filePath, "F:\\oeeee"); 
	strcat(filePath, fileName);
	FILE *file = fopen(filePath, "wb");
	if (!file){
		printf("can't open this file: %s\n", fileName);
		exit(1);
	} else {
		fwrite(person, sizeof(struct Person *), N, file);
	}
	fclose(file);
	printf("Save finished\n");
}
void display(struct Person *person){
	int i;
	for(i = 0; i < N; i++){
		printf("Person's name: %s\n", (*(person+i)).name);
		printf("Person's age: %s\n", (*(person+i)).name);
		printf("Person's job: %s", (*(person+i)).name);
	}
}
void openfile(struct Person *person){
	char fileName[100];
	char filePath[250];
	printf("Enter file name to open: "); scanf("%s", fileName);
	strcat(filePath, "F:\oeeee");
	strcat(filePath, fileName);
	FILE *file = fopen(filePath, "rb");
	if(!file){
		printf("Khong the mo duoc tep: %s\n ", file);
		exit(1);
	}else{
		fread(person, sizeof(struct Person), N, file);
	}
	fclose(file);
}
int main(int argc, char * argv[]) {
	
    printf("+-------------------------------------------------------+\n");
    printf("+ 1.Input some Persons  2.Save to file  3.Open  4.Exit. +\n");
    printf("+-------------------------------------------------------+\n");
    struct Person *person = NULL;
    char choice;        
    LABEL1: printf("Enter your choice : "); choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch (choice) {
        case '1':
            person = input();
            goto LABEL1;
            break;
        case '2':
            save(person);
            goto LABEL1;
            break;
        case '3':
            openfile(person);
            display(person);
            goto LABEL1;
            break;
        case '4':
            break;
        default:
            goto LABEL1;
            break;
    }
	return 0;
}
