#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main2(int argc, char *argv[]) {
    int i, N;
    float sum;
    printf("Enter N = "); scanf("%d", &N);
    sum = 0.0;
    for(i = 1; i<=N; i++){
        sum += 1.00/(float)i;
    }
    printf("sum = %3.2f\n", sum);
    return 0;
}
