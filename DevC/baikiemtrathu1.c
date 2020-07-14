#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Book{
	char name [100];
	char manufacter [100];
	unsigned int year;
	unsigned int price;
};
int N;
struct Book* input(){
    struct Book* book = (struct Book*)malloc(N * sizeof(struct Book));
    int i;
    printf("nhap so sach: "); scanf("%d", &N);
    for(i = 0; i < N; i++){
    	printf("sach thu %d\n", i+1);
        printf("nhap ten san pham: \n"); scanf("%s", (*(book+i)).name);
        printf("nhap nha san xuat cua san pham: \n"); scanf("%s", ((*(book+i)).manufacter));
        printf("nhap nam sx san pham: \n"); scanf("%d", &((*(book+i)).year));
        printf("nhap gia cua san pham: "); scanf("%d", &((*(book+i)).price));
    }
    return book;
}

void display(struct Book* book){
	int i;
	int sum = 0;
	for(i = 0; i < N; i++){
		printf("+------------------------------------------------+\n");
		printf("+   Name    |   Manufacter  | Year |    Price   |+ \n");
		printf("%|11s", (*(book+i)).name);
		printf("%|15s", (*(book+i)).manufacter);
		printf("%|6d", (*(book+i)).year);
		printf("%|12.2d|\n", (*(book+i)).price);
		sum++;
	}
	printf("+-----------------------------+");
	printf("total books: %d", sum);
}
void sort(struct Book* book){
	int i, j;
		for(i = 0; i < N-1; i++){
			for (j = i + 1; j < N; j++){
				if(strcmp((book+i)->name,  (book+j)->name) > 0){ 
					struct Book temp;
					temp = *(book+i);
					*(book+i) = *(book+j);
					*(book+j) = temp;
				}
			}
		}
		display(book);
}
void find(struct Book* book){
	printf("Find some book");
	struct Book *bookResults = (struct Book *)malloc(N * sizeof(struct Book));
	struct Book *ptr;
	float minPrice, maxPrice;
	char name[200];
	printf("nhap nha san xuat: "); scanf("%s", name);
	printf("nhap so tien thap nhat: "); scanf("%f", &minPrice);
	printf("nhap so tien cao nhat: "); scanf("%f", &maxPrice);
	ptr = bookResults;
	int i = 0;
	for	(i = 0; i < N; i++){
		if(strcmp((*(book+i)).name, name) == 0	&& (*(book+i)).price >= minPrice && (*(book+i)).price <= maxPrice) {
			*ptr++;
		}
	}
	printf("Sereach result");
	display(book);
}
void save(struct Book* book){
	char filename[250];
	printf("Enter file name: "); scanf("%s", filename);
	FILE* file = fopen(filename, "wb");
	if(file = NULL){
		printf("can't open file %s\n", filename);
	} else{
		fwrite(book, sizeof(struct Book *), N, file);
		fclose(file);
		printf("Data is save sucessfully \n");
	}
}
void open(struct Book* book){
	char filename[250];
	printf("Enter a file name to open"); scanf("%s", filename);
	FILE* file = fopen(filename, "rb" );
	if(!file){
		printf("can't open file %s \n", filename);
	} else{
		fread(book, sizeof(struct Book *), N, file);
		display(book);
		fclose(file);
	}
}
int main(int argc, char *argv[]) {
	struct Book* book = NULL;
	Label1:
	printf("+----------------------------------------------------------+\n");
	printf("|1.Input books|2.Sort|3.Find|4.Analyze|5.Save|6.Open|7.Exit|\n");
	printf("+----------------------------------------------------------+\n");
	char choice;
	printf("choose: ");choice=getchar();
	switch(choice){
		case 1:book = input();
		goto Label2;
		break;
		case 2: sort(book);
				goto Label2; 
				break;
		case 3: find(book);
				goto Label2; 
				break;
		case 4: 
				goto Label2; 
				break;
		case 5:	save(book);
				goto Label2; 
				break;
		case 6: open(book);
				goto Label2; 
				break;
		case 7: goto Label2; 
				break;
		default: goto Label1;
				break;
	}
	Label2:printf("Do you want exit or not\n");
			printf("choose 'Y' or 'y' to continue\n");
			printf("choose 'N' or 'n' to exit\n");
			printf("choose 'C' or 'c' to clear screen");
			printf("choose:  "); choice = getchar();
			while(choice == '\n'){
				choice = getchar();
			}
			switch (choice){
				case 'y':case 'Y': goto Label1; break;
				case 'n':
				case 'N': 
				break;
				case 'c':
				case 'C': 
				system("cls");
				break;	
				default: goto Label2;
			}
	return 0;
}
