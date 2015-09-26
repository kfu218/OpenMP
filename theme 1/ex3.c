#include <stdio.h>
#include <omp.h>

int main()
{
    int a = 0, b = 10;
    omp_set_num_threads(2);
    printf("before parallel area a = %d b = %d\n\n", a, b);
    #pragma omp parallel private(a) firstprivate(b)
    {
        int thread_num =omp_get_thread_num();
        a += thread_num;
        b += thread_num;
        printf("private-firstprivate area a = %d b = %d (thread num = %d)\n", a, b, thread_num);
    }
    printf("\nafter private-firstprivate parallel a = %d b = %d\n\n", a, b);
    omp_set_num_threads(4);
    #pragma omp parallel private(b)
    {
        int thread_num =omp_get_thread_num();
        a -= thread_num;
        b -= thread_num;
        printf("sheare-private area a = %d b = %d (thread num = %d)\n", a, b, thread_num);
    }
    printf("\nafter sheare-private parallel a = %d b = %d\n", a, b);
    return 0;
}
