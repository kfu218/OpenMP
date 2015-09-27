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
    const int N = 2;
    int a[N], b[N];

    read(a, N);
    read(b, N);

    return 0;
}
