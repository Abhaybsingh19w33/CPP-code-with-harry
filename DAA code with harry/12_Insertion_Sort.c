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

void insertionSort(int *A, int n)
{
    int i, j;
    int key;
    for (i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
        printArray(A, n);
    }
}
int main()
{
    int A[] = {5, 4, 3, 2, 1};
    //    int A[] = {1,2,3,4,5};
    int n = 5;

    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}
