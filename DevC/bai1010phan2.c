#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Item{
    char name[50];
    unsigned int rate;
    unsigned int quantity;
    unsigned int price;
};
const int N = 2;
struct Item* input(){
    struct Item* item = (struct Item*)malloc(N * sizeof(struct Item));
    int i;
    for(i = 0; i < N; i++){
        printf("nhap ten san pham[%d]: \n", i+1); scanf("%s", (*(item+i)).name);
        printf("nhap rate(danh gia) san pham[%d]: \n", i+1); scanf("%d", &((*(item+i)).rate));
        printf("nhap so luong san pham [%d]: \n", i+1); scanf("%d", &((*(item+i)).quantity));
        printf("nhap gia cua san pham [%d]: ", i+1); scanf("%d", &((*(item+i)).price));
    }
    printf("hahaa");
    return item;
}
void sort (struct Item *item){
    int i, j;
    struct Item *ptr = item;
    for (i = 0; i < N-1; i++){
        for(j = i + 1; j < N; j++){
            if(strcmp((*(ptr+i)).name,(*(ptr+j)).name) > 0){
                struct Item temp;
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
    printf("sort fisished");
}
void display(struct Item* item){
    int i;
    int sum=0;
    for(i = 0;i < N;i++){
        printf("Name:%s\n",(*(item+i)).name);
        printf("Rate:%d\n",(*(item+i)).rate);
        printf("Quantity:%d\n",(*(item+i)).quantity);
        printf("Price:%d\n",(*(item+i)).price);
        sum = sum+((*(item+i)).price) * (*(item+i)).quantity;
    }
    printf("Total price:%d\n", sum);
}

int main(int argc, char *argv[]) {
    struct Item* item = NULL;
    Label1:printf("|------------------------------------------|\n");
    printf("|1.Input some items|2.Sort|3.Display|4.Exit|\n");
    printf("|------------------------------------------|");
    
    unsigned int choice;
    printf("\nNhap so: "); scanf("%d", &choice);
    switch(choice){
        case 1: item = input();
            
            goto Label1;
            break;
        case 2: sort(item);
            goto Label1;
            break;
        case 3: display(item);
        		goto Label1;
        		break;
        case 4: break;
        default: goto Label1;
            break;
    }
    return 0;
}
