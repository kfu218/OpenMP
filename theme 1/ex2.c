#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel if (omp_get_num_threads() > 1)
    if (omp_in_parallel())
    {
        printf("threads count = %d; current threas number = %d\n", omp_get_num_threads(), omp_get_thread_num());
    }
    #pragma omp parallel if (omp_get_num_threads() == 1)
    if (omp_in_parallel())
    {
        printf("threads count = %d; current threas number = %d\n", omp_get_num_threads(), omp_get_thread_num());
    }
    return 0;
}
