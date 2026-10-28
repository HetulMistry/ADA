#include <stdio.h>

void main()
{
    int p[] = {5, 4, 6, 2, 7};
    int M[5][5] = {0};
    int S[5][5] = {0};
    int n = 5;
    int i, j, d, k, q, min;

    for (d = 1; d < n - 1; d++)
    {
        for (i = 1; i < n - d; i++)
        {
            j = i + d;
            k = i;
            min = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
            S[i][j] = k;

            for (k = i + 1; k < j; k++)
            {
                q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < min)
                {
                    min = q;
                    S[i][j] = k;
                }
            }

            M[i][j] = min;
        }
    }
    printf("Minimum number of multiplications: %d\n", M[1][n - 1]);
}