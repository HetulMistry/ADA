
#include <stdio.h>

int factorial(int n)
{
    if (n < 0)
        return -1;
    else if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int n, fact;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
    {
        fact = factorial(n);
        printf("Factorial of %d is %d\n", n, fact);
    }

    return 0;
}
