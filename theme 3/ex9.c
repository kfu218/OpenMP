#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void initMatrix(int matrix[][10], int n, int m)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 100;
}

void printMatrix(int matrix[][10], int n, int m)
{
    printf("n = %d, m = %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void max_min(int matrix[][10], int n, int m)
{
    int min = matrix[0][0], max = matrix[0][0];
    printf("n = %d, m = %d\n", n, m);
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // if (matrix[i][j] > max || matrix[i][j] < min)
                #pragma omp critical
                {
                    if (matrix[i][j] < min)
                        min = matrix[i][j];
                    else if (matrix[i][j] > max)
                        max = matrix[i][j];
                }
        }
    printf("min = %d, max = %d\n", min, max);
}

int main()
{
    const int N = 6, M = 8;
    int A[N][M];
    initMatrix(A, 6, 8);
    printMatrix(A, 6, 8);
    printf("N = %d, M = %d\n", N, M);
    max_min(A, 6, 8);
    return 0;
}
