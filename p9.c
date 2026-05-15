#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void selectionSort(int a[MAX], int n);

void main()
{
    srand(time(NULL));
    int n, a[MAX], i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Generated elements are:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 200;
        printf("%d ", a[i]);
    }

    clock_t start = clock();
    selectionSort(a, n);
    clock_t stop = clock();

    double elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC * 1000;
    printf("\nTime elapsed in ms: %lf\n", elapsed);
}

void selectionSort(int a[MAX], int n)
{
    int i, j, temp, min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }

    printf("\nSorted list:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}