#include <stdio.h>

// =============================================
// max() — do values mein se bada return karo
// =============================================
int max(int i, int j)
{
    if (i > j)
        return i;
    else
        return j;
}

// =============================================
// displayinfo() — input table print karo
// =============================================
void displayinfo(int m, int n, int w[], int p[])
{
    printf("Entered information about knapsack problem:\n");
    printf("ITEM\tWEIGHT\tPROFIT\n");
    for (int i = 1; i <= n; i++)
        printf("%d\t%d\t%d\n", i, w[i], p[i]);
    printf("Capacity = %d\n", m);
}

// =============================================
// knapsack() — DP table fill karo
// v[i][j] = max profit using i items, capacity j
// =============================================
void knapsack(int m, int n, int w[], int p[], int v[][10])
{
    for (int i = 0; i <= n; i++)        // har item ke liye (0 = no item)
    {
        for (int j = 0; j <= m; j++)    // har capacity ke liye (0 to m)
        {
            // Case 1: Base case
            // No items ya capacity 0 — profit 0
            if (i == 0 || j == 0)
                v[i][j] = 0;

            // Case 2: Item ka weight capacity se zyada
            // Item fit nahi hoga — skip, upar wali row copy karo
            else if (j < w[i])
                v[i][j] = v[i-1][j];

            // Case 3: Item fit ho sakta hai
            // max(skip item, take item) — jo zyada profit de
            else
                v[i][j] = max(
                    v[i-1][j],               // item mat lo
                    v[i-1][j - w[i]] + p[i] // item lo
                );
        }
    }
}

// =============================================
// optimal() — backtracking se kaunse items liye
// Table ke last cell se reverse trace karo
// =============================================
void optimal(int m, int n, int w[], int v[][10])
{
    int i = n;          // last item se shuru (bottom row)
    int j = m;          // full capacity se shuru (last column)
    int x[10] = {0};   // x[i]=1 means item i selected

    printf("\nOptimal solution (max profit) = %d\n", v[n][m]);

    // Jab tak items hain aur capacity bachi hai
    while (i != 0 && j != 0)
    {
        // Value upar wali row se alag hai?
        // Matlab item i liya gaya tha
        if (v[i][j] != v[i-1][j])
        {
            x[i] = 1;       // item i mark karo as selected
            j = j - w[i];  // capacity se us item ka weight hatao
        }
        // Ek row upar jao — chahe item liya ya nahi
        i = i - 1;
    }

    // Selected items print karo
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

    // Agar koi item fit nahi hua
    if (found == 0)
        printf("NIL - No item fits in knapsack");

    printf("\n");
}

// =============================================
// main() — input lo, functions call karo
// =============================================
int main()
{
    int v[10][10];  // DP table — v[i][j]
    int w[10];      // weight of each item
    int p[10];      // profit of each item
    int n, m;       // n = number of items, m = capacity

    printf("************* KNAPSACK PROBLEM ***********\n");

    // Number of items input
    printf("Enter the total number of items: ");
    scanf("%d", &n);

    // Weights input — 1-indexed
    printf("Enter the weight of each item:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    // Profits input — 1-indexed
    printf("Enter the profit of each item:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    // Knapsack capacity input
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);

    // Input info display karo
    displayinfo(m, n, w, p);

    // DP table fill karo
    knapsack(m, n, w, p, v);

    // DP table print karo
    printf("\nThe DP table (v[i][j]) is:\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            printf("%d\t", v[i][j]);
        printf("\n");
    }

    // Backtracking — optimal items find karo
    optimal(m, n, w, v);

    printf("\n*****************************************\n");
    return 0;
}