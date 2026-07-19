#include <stdio.h>
int max(int i, int j)
{
    if (i > j)
        return i;
    else
        return j;
}
void displayinfo(int m, int n, int w[], int p[])
{
    printf("Entered information about knapsack problem:\n");
    printf("ITEM\tWEIGHT\tPROFIT\n");
    for (int i = 1; i <= n; i++)
        printf("%d\t%d\t%d\n", i, w[i], p[i]);
    printf("Capacity = %d\n", m);
}
void knapsack(int m, int n, int w[], int p[], int v[][10])
{
    for (int i = 0; i <= n; i++)   
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;

            else if (j < w[i])
                v[i][j] = v[i-1][j];

            else
                v[i][j] = max(v[i-1][j],v[i-1][j - w[i]] + p[i]);
        }
    }
}

void optimal(int m, int n, int w[], int v[][10])
{
    int i = n;          // last item se shuru (bottom row)
    int j = m;          // full capacity se shuru (last column)
    int x[10] = {0};   // x[i]=1 means item i selected

    printf("\nOptimal solution (max profit) = %d\n", v[n][m]);

    while (i != 0 && j != 0)
    {
        if (v[i][j] != v[i-1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        i = i - 1;
    }

    printf("Selected items are: ");
    int found = 0;
    for (i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            printf("%d ", i);
            found = 1;
        }
    }
    if (found == 0)
        printf("NIL - No item fits in knapsack");

    printf("\n");
}

int main()
{
    int v[10][10];
    int w[10];
    int p[10];
    int n, m;

    printf("Enter the total number of items: ");
    scanf("%d", &n);

    printf("Enter the weight of each item:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the profit of each item:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);
    displayinfo(m, n, w, p);

    knapsack(m, n, w, p, v);

    printf("\nThe DP table (v[i][j]) is:\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            printf("%d\t", v[i][j]);
        printf("\n");
    }

    optimal(m, n, w, v);

    return 0;
}