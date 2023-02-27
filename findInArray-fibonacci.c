#include <stdio.h>

int IsInArray();
void printFib();

void main()
{
    int arr_length;
    printf("Enter length of array - ");
    scanf("%d", &arr_length);

    int array[arr_length];
    for (int i = 0; i < arr_length; i++)
    {
        printf("Enter the %d element in the array - ", i + 1);
        scanf("%d", &array[i]);
    }

    int num_to_find;
    printf("Enter number to find in array - ");
    scanf("%d", &num_to_find);

    if (IsInArray(num_to_find, array, arr_length) == 1)
    {
        printf("Yes %d is in array", num_to_find);
    }
    else
    {
        printf("%d is not in array", num_to_find);
    }

    int fib_num;
    printf("\nEnter number till fibonacci - ");
    scanf("%d", &fib_num);

    printFib(fib_num);
}

int IsInArray(int num, int arr[], int arr_length)
{

    for (int i = 0; i < arr_length; i++)
    {
        if (num == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

void printFib(int num)
{

    int t1 = 0, t2 = 1;

    int nextTerm = t1 + t2;

    for (int i = 1; i <= num; ++i)
    {
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}