#include <stdio.h>
#define MAX 20

int GraphMatrix[MAX][MAX], visited[MAX], Nodes;

void DFS(int v)
{
    int w;
    visited[v] = 1;
    printf("%d ", v);

    for (w = 0; w < Nodes; w++)
        if (GraphMatrix[v][w] == 1 && visited[w] != 1)
            DFS(w);
}

int main()
{
    int edges, src, dest, i, j;

    printf("Enter no. of nodes: ");
    scanf("%d", &Nodes);

    printf("Enter no. of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < Nodes; i++)
        for (j = 0; j < Nodes; j++)
            GraphMatrix[i][j] = 0;

    printf("Enter edges (src dest):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        GraphMatrix[src][dest] = 1;
        GraphMatrix[dest][src] = 1;
    }

    for (i = 0; i < Nodes; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from node 0:\n");
    DFS(0);

    return 0;
}