#include <stdio.h>

// Function declarations
void floyd(int a[10][10], int n);
int min(int a, int b);

int main()
{
    int a[10][10], i, j, n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            // Convention: enter 999 for no direct edge (infinity)
        }
    }

    // Print the input matrix
    printf("Entered adjacency matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Call Floyd-Warshall algorithm
    floyd(a, n);

    // Print the result (shortest path matrix)
    printf("All pair shortest path matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Floyd-Warshall Algorithm
// Idea: Try every vertex 'k' as an intermediate node
// between every pair (i, j) and update shortest path
void floyd(int a[10][10], int n)
{
    int k, i, j;

    // k = intermediate vertex (1 to n)
    for (k = 1; k <= n; k++)
    {
        // i = source vertex
        for (i = 1; i <= n; i++)
        {
            // j = destination vertex
            for (j = 1; j <= n; j++)
            {
                // If going i -> k -> j is shorter than i -> j directly,
                // update a[i][j] with the shorter path
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}

// Returns the smaller of two integers
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}