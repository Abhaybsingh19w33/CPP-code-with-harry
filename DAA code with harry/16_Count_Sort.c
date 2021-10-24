#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//#include <bits/stdc++.h>

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

void Merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    int B[100];

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void CountSort(int *A, int n)
{
    int max = maximum(A, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    int i, j;
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int maximum(int A[], int n)
{
    int i;
    int max = INT_MIN;
    for (i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
int main()
{
    int A[] = {5, 4, 3, 2, 1};
    //    int A[] = {1,2,3,4,5};
    int n = 5;
    printArray(A, n);
    CountSort(A,n);
    printArray(A, n);
    return 0;
}
