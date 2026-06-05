#include <stdio.h>

int c = 0;

void subset(int cs, int k, int r, int x[], int w[], int d, int n) {
    x[k] = 1;

    if (cs + w[k] == d) {
        c++;
        printf("\nSolution %d is { ", c);
        for (int i = 0; i <= k; i++)
            if (x[i] == 1)
                printf("%d ", w[i]);
        printf("}\n");
    }
    else if (k + 1 < n && (cs + w[k] + w[k+1]) <= d) {
        subset(cs + w[k], k+1, r - w[k], x, w, d, n);
    }

    if (k + 1 < n && (cs + r - w[k]) >= d && (cs + w[k+1]) <= d) {
        x[k] = 0;
        subset(cs, k+1, r - w[k], x, w, d, n);
    }

    x[k] = 0;  // reset before returning
}

int main() {
    int w[10], x[10], n, d, i, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in increasing order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        x[i] = 0;  // initialize x[]
    }

    printf("Enter the Positive Sum: ");
    scanf("%d", &d);

    for (i = 0; i < n; i++)
        sum = sum + w[i];

    printf("SUM = %d\n", sum);

    if (sum < d || w[0] > d) {
        printf("Subset is not possible!\n");
        return 0;
    }

    subset(0, 0, sum, x, w, d, n);

    if (c == 0)
        printf("Subset is not possible!\n");

    return 0;
}

