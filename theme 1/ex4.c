#include <stdio.h>
#include <omp.h>

void read(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int main()
{
    const int N = 10;
    int a[N], b[N];
    int min, max;

    read(a, N);
    read(b, N);

    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0)
        {
            min = a[0];
            for(int i = 0; i < N; i++)
            {
                if (a[i] < min)
                    min = a[i];
            }
        }
    }

    #pragma omp parallel
    {
        if (omp_get_thread_num() == 1)
        {
            max = b[0];
            for(int i = 0; i < N; i++)
            {
                if (b[i] > max)
                    max = b[i];
            }
        }
    }

    printf("a min = %d; b max = %d\n", min, max);

    return 0;
}
