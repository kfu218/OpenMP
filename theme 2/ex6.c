#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void randInit(int array[], const int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        array[i] = rand() % 100;
}

double mean(int array[], const int n)
{
    double sum = 0;
    #pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < n; i++)
        sum += array[i];
    return (double)sum / n;
}

int main()
{
    const int N = 10;
    int a[N], b[N];
    randInit(a, N);
    randInit(b, N);
    printf("a mean == %f; b mean == %f\n", mean(a, N), mean(b, N));
    return 0;
}
