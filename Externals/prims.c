#include<stdio.h>

void prims(int cost[10][10], int n)
{
    int visited[10] = {0}; // all nodes unvisited
    int i, j, min, mincost = 0, a, b, ne = 1;

    visited[1] = 1; // start from node 1

    // loop runs n-1 times to find n-1 edges
    while(ne < n)
    {
        min = 999; // reset min each time

        // check all visited to unvisited edges
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                // i must be visited, j must be unvisited
                // and edge must be minimum
                if(visited[i] && !visited[j] && cost[i][j] < min)
                {
                    min = cost[i][j]; // store minimum cost
                    a = i;            // store from node
                    b = j;            // store to node
                }
            }
        }

        // print selected edge
        printf("(%d,%d) = %d\n", a, b, min);

        mincost += min;  // add edge cost to total
        visited[b] = 1;  // mark b as visited
        ne++;            // increment edge count
    }

    printf("\nMinimum Cost = %d", mincost);
}

int main()
{
    int cost[10][10], n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("\n your enetrd adjacancy matrix is :\n");
   for(int p = 1; p <= n; p++)
    {
        for(int q = 1; q <= n; q++)
        {
            printf("%d\t",cost[p][q]);
        }
        printf("\n");
    }
    printf("\n");
 

    prims(cost, n);
    return 0;
}