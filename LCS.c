#include <stdio.h>
#include <string.h>

#define MAX 100

int c[MAX][MAX];
char dir[MAX][MAX], s1[MAX][MAX], s2[MAX][MAX];
int m, n;

void printLCS(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (dir[i][j] == 'S')
    {
        printLCS(i - 1, j - 1);
        printf("%c", s1[i - 1]);
    }
    else if (dir[i][j] == 'U')
        printLCS(i - 1, j);
    else
        printLCS(i, j - 1);
}

void LCS()
{
    m = strlen(s1);
    n = strlen(s2);

    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                dir[i][j] = 'S';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                dir[i][j] = 'U';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                dir[i][j] = 'L';
            }
}

int main()
{
    printf("Enter string1: ");
    scanf("%s", s1);

    printf("Enter string2: ");
    scanf("%s", s2);

    LCS();

    printf("Length of LCS: %d\n", c[m][n]);
    printf("Longest Common Subsequence: ");
    printLCS(m, n);
    printf("\n");

    for (int i = 0; i <= m; i++)
    {
        printf(" | ");
        for (int j = 0; j <= n; j++)
            printf("%d %c", c[i][j], dir[i][j]);
        printf("\n");
    }

    return 0;
}