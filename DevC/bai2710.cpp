#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Product{
	char name[50];
	unsigned int manufacture_year;
	char manufacter[100];
};
int N;
struct Product* input(){
	struct Product* product = (struct Product *)malloc(N * sizeof(struct Product));
	int i;
		for(i = 0; i < 5; i++){
			printf("san pham thu nhat %d\n", i);
			printf("nhap ten san pham: "); scanf("%s", (*(product+i)).name);
			printf("nhap nam san xuat: "); scanf("%d", &(*(product+i)).manufacture_year);
			printf("nhap nha san suat: "); scanf("%s", (*(product+i)).manufacter);
		}
		return product;
}
void display(struct Product *product) {
    int i;
    for(i = 0; i < 5; i++){
        printf("Product's name : %s\n", (*(product+i)).name);
        printf("Product's manufacture_year : %d\n", (*(product+i)).manufacture_year);
        printf("Product's manufacture : %s\n", (*(product+i)).manufacter);
    }
}
void sort(struct Product* product){
	int i, j;
		struct Product *ptr = product;
		for(i = 0; i < N - 1; i++){
			for(j = i + 1; j < N; j++){
			if(strcmp((*(ptr+i)).name, (*(ptr+j)).name) > 0) {
				struct Product temp;
					temp = *(ptr+i);
					*(ptr+i) = *(ptr+j);
					*(ptr+j) = temp;
			}		
		}
	}
	printf("sort finished\n");
	display(product);
}
int main(int argc, char * argv[]) {
    printf("+--------------------------------------------------+\n");
    printf("+ 1.Input some Product  2.Sort  3.Display  4.Exit. +\n");
    printf("+--------------------------------------------------+\n");
    struct Product *product = NULL;
    char choice;
    LABEL1: printf("Enter your choice : "); choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch (choice) {
        case '1':
            product = input();
            goto LABEL1;
            break;
        case '2':
            sort(product);
            goto LABEL1;
            break;
        case '3':
            display(product);
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

