#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        printf("%d %d Hello, World!\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}
