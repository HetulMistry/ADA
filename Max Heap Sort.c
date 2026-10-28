#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeap(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        maxHeap(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        maxHeap(a, i, 0);
    }
}

int main()
{
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = 6, i;

    heapSort(a, n);

    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}