
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void binaryKnapsack(int W, int weights[], int values[], int n)
{
    int i, w, dp[n + 1][W + 1];

    for (i = 0; i <= n; i++)
        for (w = 0; w <= W; w++)
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];

    int maxProfit = dp[n][W];

    printf("Maximum Values/Profit: %d\n", maxProfit);
    printf("Selected Items:\n");
    printf("Item   Weight     Value\n");

    int res = maxProfit;

    for (i = n; i > 0 && res > 0; i--)
        if (res != dp[i - 1][W])
        {
            printf("%-6d %-10d %-10d\n",
                   i, weights[i - 1], values[i - 1]);

            res -= values[i - 1];
            W -= weights[i - 1];
        }
}

int main()
{
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    printf("Knapsack Capacity: %d\n", W);
    binaryKnapsack(W, weights, values, n);

    return 0;
}