#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main1(int argc, char *argv[]) {
    int i, N;
    float sum;
    printf("Enter N = "); scanf("%d", &N);
    sum = 0.0;
    for(i = 0; i<N; i++){
        sum += pow((float)(i+1), 1.00/3.00);
    }
    printf("sum = %3.2f", sum);
    return 0;
}
