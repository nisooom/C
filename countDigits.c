#include <stdio.h>
#include <string.h>

void main()
{

    int count = 0, n;

    printf("Enter Number - ");
    scanf("%d", &n);

    while (n != 0)
    {
        n /= 10;
        ++count;
    }

    printf("%d", count);
}