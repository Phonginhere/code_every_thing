#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Book {
    char name[220];//fields = properties
    char publisher[250];
    int year;
    float price;
};
int N;
struct Book* input() {//this is a function
    printf("Enter number of books: "); scanf("%d", &N);
    struct Book *book = (struct Book *)malloc(N * sizeof(struct Book));
    int i;
    for (i = 0; i < N; i++) {
        INPUT_ONE: printf("Book number %d : \n", i+1);
        printf("Enter book's name : ");scanf("%s", (book+i)->name);
        //scanf("%s", (*(book+i)).name);
        printf("Enter book's year : "); scanf("%d", &(book+i)->year);
        //Validate input ?
        if((book+i)->year <= 2000) {
            printf("Year must be > 2000\n");
            printf("Please re-enter your book's information\n");
            goto INPUT_ONE;
        }
        printf("Enter book's publisher :");scanf("%s", (book+i)->publisher);
        printf("Enter book's price($) :");scanf("%f", &(book+i)->price);
        if((book + i)->price < 100 || (book + i)->price > 200){
            printf("Price >= 100, price <= 200\n");
            printf("Please re-enter your book's information\n");
            goto INPUT_ONE;
        }
    }
    return book;
}
int main(int argc, char *argv[]) {
	struct Book* book = NULL;
	book = input();
	return 0;
}
