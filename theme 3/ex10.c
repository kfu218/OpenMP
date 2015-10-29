#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void initVector(int vector[], const int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vector[i] = rand() % 100 + 1;
}

void printVector(int vector[], const int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", vector[i]);
    printf("\n");
}

int countOfNine(int vector[], const int n)
{
    int count = 0;
    omp_set_num_threads(4);
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        if (vector[i] % 9 == 0)
        {
        #pragma omp atomic
            count++;
        }
    }
    return count;
}

int main()
{
    const int N = 30;
    int a[N];
    initVector(a, N);
    printVector(a, N);
    printf("count = %d\n", countOfNine(a, N));
    return 0;
}
