#include <stdio.h>

void main()
{
    int n, amount;

    printf("Enter no. of coins: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coins values: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];

    for (int i = 0; i <= amount; i++)
        dp[i] = amount + 1;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int j = 0; j < n; j++)
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
                dp[i] = dp[i - coins[j]] + 1;

    if (dp[amount] > amount)
        printf("No solution possible\n");
    else
        printf("Minimum coins required: %d\n", dp[amount]);
}
