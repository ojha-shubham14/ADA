#include <stdio.h>
#include <stdlib.h>  // for abs()

int count = 0, x[20];

int place(int k, int i) {
    for ( int j = 0; j < k; j++)
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    return 1;
}

void nqueen(int k, int n) {
    int i, j, p;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                count++;
                printf("Solution = %d\n", count);
                for (j = 1; j <= n; j++) {
                    for (p = 1; p <= n; p++) {
                        if (x[j] == p)
                            printf("Q\t");
                        else
                            printf(".\t");
                    }
                    printf("\n");
                }
                printf("\n");
            } else {
                nqueen(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nqueen(1, n);
    if (count == 0)
        printf("No solution found.\n");
    else
        printf("Number of solutions found: %d\n", count);
    return 0;
}