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

void bubbleSort(int *A, int n)
{
    int i, j;
    int isSorted = 0;
    for (i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d \n", i+1);
        isSorted = 1;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
        printArray(A, n);
    }
}
int main()
{
    int A[] = {5, 4, 3, 2, 1};
//    int A[] = {1,2,3,4,5};
    int n = 5;

    printArray(A, n);
    bubbleSort(A, n);
    printArray(A, n);
    return 0;
}
