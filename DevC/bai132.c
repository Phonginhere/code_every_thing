#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b, c, d, e, f, g, h;
    printf("nhap canh 1:"); scanf("%d", &a);
    printf("nhap canh 2:"); scanf("%d", &b);
    printf("nhap canh 3:"); scanf("%d", &c);
    d = a * a;
    e = b * b;
    f = c * c;
    d = e + f;
    e = d + f;
    f = d + e;
    if(a == b || b == c || c == a){
        printf("tam giac can");
    }else if(a == b && a == c && c == b){
        printf("tam giac deu");
    }else if(a != b && a != c && b != c){
        printf("tam giac thuong");
    }else{
        printf("tam giac vuong");
    }
	return 0;
}
