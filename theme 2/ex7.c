#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main()
{
    const int N = 12;
    int a[N], b[N], c[N];
    srand(time(NULL));
    printf("static schedule\n");
    omp_set_num_threads(3);
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 100;
        b[i] = rand() % 200;
        printf("thread num %d, %d iteration, a[i] = %d, b[i] = %d\n", omp_get_thread_num(), i, a[i], b[i]);
    }

    printf("\ndynamic schedule\n");
    omp_set_num_threads(4);
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
        printf("thread num %d, %d iteration, c[i] = %d\n", omp_get_thread_num(), i, c[i]);
    }
    return 0;
}
