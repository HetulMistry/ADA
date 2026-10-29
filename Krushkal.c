#include <stdio.h>

#define MAX 100

struct Edge
{
    int src, dest, weight;
};

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    struct Edge edges[MAX], temp;
    int n, e, i, j;
    int totalCost = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    if (n < 1 || n > MAX || e < 0 || e > MAX)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter edges (source, destination, weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    for (i = 0; i < e - 1; i++)
        for (j = 0; j < e - 1 - i; j++)
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v))
        {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            totalCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    if (count != n - 1)
    {
        printf("Graph is disconnected! MST does not exist.\n");
        return 1;
    }

    printf("Total cost of Minimum Spanning Tree: %d\n", totalCost);

    return 0;
}