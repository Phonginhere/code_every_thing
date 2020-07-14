#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Person{
	char name [50];
	char age [50];
	char job [100];
};
void Person (){
    printf("Numbers of Persons : ");scanf("%d", &N);
    struct Person *Person = (struct Person *)malloc(N * sizeof(struct Person));
    int i;
    for (i = 0; i < N; i++){
        printf("Person number %d :\n", i+1);
    	printf("Enter Person's name : \n");scanf("%s", (*(Person+i)).name);
    	printf("Enter Person's age : \n");scanf("%d", &((*(Person+i)).age));
    	printf("Enter Person's job : \n");scanf("%s", (*(Person+i)).job);
    }
}
void save(char path[100], char content[500]){
	FILE *fo = fopen(path, "w+");
	if (fo == NULL){
		printf("Can't open this file\n");
	}
	fputs(content, fo);
	printf("Save successful!!");
	fclose(fo);
}
void display(struct Person *person) {
    int i;
    for(i = 0; i < N; i++){
        printf("Person's name : %s\n", (*(person+i)).name);
        printf("Person's age : %d\n", (*(person+i)).age);
        printf("Person's job : %s\n", (*(person+i)).job);
    }
}
void openFile(struct Person *person) {
    char fileName[100];
    char filePath[250];
    printf("Enter file name to open : "); scanf("%s", fileName);
    strcat(filePath, "D:\\");
    strcat(filePath, fileName);
    FILE *file = fopen(filePath,"rb"); 
    
    if (!file) {
        printf("Cannot open file %s\n", fileName);
        exit(1);
    } else {
        fread(person, sizeof(struct Person), N, file);
    }
    fclose(file);
}
int main(int argc, char *argv[]) {
	int select; char file;
	int N, i; FILE *fp;
	int x,f;
	BACK: printf("1.Input some persons\n");
	printf("2.Save to file\n");
	printf("3.Open\n");
	printf("4.Exit\n");
	printf("nhap so: "); scanf("%d", &select);
	switch (select){
		case 1: Person();
				goto BACK;
				break;
		case 2: char path[100];
				printf("Enter the name of the file");
				scanf("%s", path);
				
				strcat(path, ".txt");
				Person();
				save(path, content);
		case 4: printf("Thoat khoi chuong trinh");
				break;		
	}
	return 0;
}

