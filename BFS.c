#include <stdio.h>

int f = -1, r = -1;
int visited[10], q[10];

void BFS(int mat[10][10], int v)
{
    int sv = 0, c;
    q[++r] = sv;
    visited[sv] = 1;

    printf("BFS Traversal: ");

    while (f < r)
    {
        sv = q[++f];
        printf("%d ", sv);
        for (c = 0; c < v; c++)
            if (mat[sv][c] == 1 && !visited[c])
            {
                visited[c] = 1;
                q[++r] = c;
            }
    }
    printf("\n");
}

int main()
{
    int mat[10][10];
    int v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            scanf("%d", &mat[i][j]);

    for (i = 0; i < v; i++)
        visited[i] = 0;

    BFS(mat, v);

    return 0;
}