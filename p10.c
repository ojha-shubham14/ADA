#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void display(int a[], int low, int high)
{
    int i;
    printf("\nElements after sorting are:\n");
    for (i = 0; i <= high; i++)
    {
        printf("%d\t", a[i]);
    }
}

int main()
{
    int n;
    int a[MAX];
    printf("Enter the number of elements N to perform MERGE SORT: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 500;
        printf("%d\t", a[i]);
    }

    clock_t start = clock();
    mergesort(a, 0, n - 1);
    display(a, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken to sort %d elements: %f milliseconds\n", n, time_taken);

    return 0;
}