#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// sua lai bai
struct Product{
	char name[50];
	unsigned int manufacture_year;
	char manufacter[100];
	int price;
};
int N;
struct Product* input(){
	struct Product* product = (struct Product *)malloc(N * sizeof(struct Product));
	int i;
		for(i = 0; i < 2; i++){
			printf("san pham thu nhat %d\n", i);
			printf("nhap ten san pham: "); scanf("%s", (*(product+i)).name);
			printf("nhap nam san xuat: "); scanf("%d", &(*(product+i)).manufacture_year);
			printf("nhap nha san suat: "); scanf("%s", (*(product+i)).manufacter);
			printf("nhap so tien: "); scanf("%d", (*(product+i)).price);
		}
		return product;
}
void display(struct Product *product) {
    int i;
    for(i = 0; i < 5; i++){
        printf("Product's name : %s\n", (*(product+i)).name);
        printf("Product's manufacture_year : %d\n", (*(product+i)).manufacture_year);
        printf("Product's manufacture : %s\n", (*(product+i)).manufacter);
        printf("nhap so tien: "); scanf("%d", (*(product+i)).price);
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
void find(struct Product *product) {
    printf("Find some products \n");
    struct Product *productResults = (struct Product *)malloc(N * sizeof(struct Product));
    struct Product *ptr;
    int i = 0;
    float maxPrice, minPrice;
    char manufacture[200];
    printf("Product's manufacture: "); scanf("%s", (*(product)).name);
    printf("Enter min price: "); scanf("%f", &minPrice);
    printf("Enter max price: "); scanf("%f", &maxPrice);
    ptr = productResults;
    int j = 0;
    for(i = 0; i < N; i++){
        if(strcmp((*(product+i)).name, manufacture) == 0 &&
           (*(product+i)).price >= minPrice && (*(product+i)).price <= maxPrice ){
            *ptr = *(product+i);
            ptr++;
            j++;
        }
    }
    printf("Search result : \n");
    for(i = 0; i < j; i++){
        printf("Product's name : %s\n", (*(productResults+i)).name);
        printf("Product's year : %d\n", (*(productResults+i)).manufacture_year);
        printf("Product's manufacture : %s\n", (*(productResults+i)).manufacter);
        printf("Product's price : %f\n", (*(productResults+i)).price);
    }
}
int main(int argc, char * argv[]) {
 LABEL1:printf("+--------------------------------------------------+\n");
    printf("+ 1.Input some Product  2.Sort  3.Display  4.Exit. +\n");
    printf("+--------------------------------------------------+\n");
    struct Product *product = NULL;
    char choice, choose;
    printf("Enter your choice : "); choice = getchar();
    while (choice == '\n') {
        choice = getchar();
    }
    switch (choice) {
        case '1':
            product = input();
            goto Label2;
            break;
        case '2':
            sort(product);
            goto Label2;
            break;
        case '3':
            display(product);
            goto Label2;
            break;
        case '4': 
        		find(product);
        		goto Label2;
        		break;
        case '5':
            break;
        default:
            goto LABEL1;
            break;
    }
    Label2: printf("Do you want to continue ?\n");
    		printf("- Yes, I do. (press y, Y)\n");
    		printf("- No, I don't'. (press n, N)\n");
    		printf("- Clear the screen ! (press c, C)\n");
    		printf("nhap so: "); choose = getchar();
    		while (choose == '\n'){
    			choose = getchar();
			}
			switch (choose){
				case 'Y':
				case 'y': goto LABEL1;
							break;
				case 'n':
				case 'N': break;
				case 'c':
				case 'C': system("cls");
				default: goto Label2; 
			}
    return 0;
}

