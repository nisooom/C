#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    // Check if n=1 or n=0
    if (n <= 1)
        return 0;
    // Check if n=2 or n=3
    if (n == 2 || n == 3)
        return 1;
    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}

int main()
{
    int n;
    printf("Enter Number - ");
    scanf("%d", &n);

    float sr;
    sr = sqrt(n);
    printf("the square root is = ");
    printf("%.3f", sr);
    printf("\n");

    int sq = n * n;
    printf("the square is = ");
    printf("%d", sq);
    printf("\n");

    int cb = n * n * n;
    printf("the cube is = ");
    printf("%d", cb);
    printf("\n");

    int sum = 1;
    for (int i = 1; i < n + 1; i++)
    {
        sum = sum * i;
    }
    printf("the factorial is - %d\n", sum);

        if (isPrime(n) == 1)
        printf("the number is a prime number\n");
    else
        printf("the number isnt prime\n");
    return 0;
}