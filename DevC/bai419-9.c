#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main4(int argc, char *argv[]) {
    int i, N;
    int min;
    int x;
    printf("Enter N = "); scanf("%d", &N);
    min = 65535;
    for(i = 0; i < N; i++){
        printf("Nhap x: "); scanf("%d", &x);
        if(x < min) {
            min = x;
        }
    }
    printf("min = %d\n", min);
    return 0;
}
