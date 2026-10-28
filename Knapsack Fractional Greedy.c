#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    float p[20], w[20], r[20], c, tp = 0;
    int n, i, j;

    printf("Enter no. of items: ");
    scanf("%d", &n);

    printf("Enter profit for %d items: ", n);
    for (i = 0; i < n; i++)
        scanf("%f", &p[i]);

    printf("Enter weight for %d items: ", n);
    for (i = 0; i < n; i++)
        scanf("%f", &w[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%f", &c);

    for (i = 0; i < n; i++)
        r[i] = p[i] / w[i];

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (r[j] < r[j + 1])
            {
                swap(&r[j], &r[j + 1]);
                swap(&p[j], &p[j + 1]);
                swap(&w[j], &w[j + 1]);
            }

    for (i = 0; i < n; i++)
        if (w[i] <= c)
        {
            tp += p[i];
            c -= w[i];
        }
        else
        {
            tp += r[i] * c;
            break;
        }

    printf("Maximum profit: %f\n", tp);

    return 0;
}