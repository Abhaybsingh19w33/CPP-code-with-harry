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

int partition(int A[], int low, int high)
{
	printf("in partition\n");
    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (A[i] <= pivot) 
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j) 
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void QuickSort(int A[], int low, int high)
{
	printf("in quicksort\n");
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        QuickSort(A, low, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, high);
    }
}
int main()
{
    int A[] = {5, 4, 3, 2, 1};
    //    int A[] = {1,2,3,4,5};
    int n = 5;
    printArray(A, n);
    QuickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}
