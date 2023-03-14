#include <stdio.h>
#include <conio.h>


int peek(int *stack);
int pop(int *stack);
int push(int *stack);
int printInstructions();

int top = -1, maxsize;

int main()
{
    int i;

    printf("Enter Length of Stack - ");
    scanf("%d", &maxsize);

    int stack[maxsize];
    int choice;

    while (choice != 4)
    {
        choice = printInstructions();
        switch (choice)
        {
        case 1:
            push(stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            peek(stack);
        case 4:
            choice = 4;
            break;
        default:
            printf("Try Again\n");
            break;
        }
    }

    return 0;
}

int printInstructions()
{
    int choice = 0;
    printf("Enter 1 to add to Stack",
           "\nEnter 2 to remove top element from stack",
           "\nEnter 3 to peek at top element of stack",
           "\nEnter 4 to close program",
           "\n->");
    scanf("%d", &choice);
    return choice;
}