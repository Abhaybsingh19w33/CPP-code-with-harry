#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfMin;
    int i, j;
    int temp;
    for (i = 0; i <= n - 1; i++)
    {
        indexOfMin = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
        printArray(A, n);
    }
}
int main()
{
    int A[] = {5, 4, 3, 2, 1};
    //    int A[] = {1,2,3,4,5};
    int n = 5;

    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}
