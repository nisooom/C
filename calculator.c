#include <stdio.h>

void main()
{
    int a, b, opt;
    float ans;

    printf("Enter number 1 - ");
    scanf("%d", &a);
    printf("\nEnter number 1 - ");
    scanf("%d", &b);

    printf("\nEnter 1 for Addition");
    printf("\nEnter 2 for Subtraction");
    printf("\nEnter 3 for Multiplication");
    printf("\nEnter 4 for Division");
    printf("\n ->");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        ans = a + b;
        break;
    case 2:
        ans = a - b;
        break;
    case 3:
        ans = a * b;
        break;
    case 4:
        if (b > 0)
        {
            ans = a / b;
        }
        else
        {
            ans = 0;
        }
        /* code */
        break;

    default:
        printf("Error Occured.");
        break;
    }
}