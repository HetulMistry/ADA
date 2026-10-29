#include <stdio.h>

#define MAX 100
#define INF 9999

int main()
{
    int n, i, j, cost[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0, min, u, v;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    visited[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
            if (visited[i])
                for (j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }

        if (min == INF)
        {
            printf("Graph is disconnected!\n");
            return 1;
        }

        visited[v] = 1;

        printf("%d - %d : %d\n", u, v, min);

        totalCost += min;
        edges++;
    }

    printf("Total cost of Minimum Spanning Tree: %d\n",
           totalCost);

    return 0;
}