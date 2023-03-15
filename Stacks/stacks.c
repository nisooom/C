//
// Created by nishu on 27-02-2023.
//

#include <stdio.h>

void peek(int *stack);
void pop(int *stack);
void push(int *stack);
int printInstructions();
int isEmpty();
int isFull();

int top = -1, maxsize;

int main() {
    printf("Enter Length of Stack -  ");
    scanf("%d", &maxsize);

    int stack[maxsize];
    int choice = 0;

    while (choice != 4) {
        choice = printInstructions();
        switch (choice) {
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                peek(stack);
                break;
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

int isEmpty() {
    return top == -1 ? 1 : 0;
}

int isFull() {
    return top == maxsize - 1 ? 1 : 0;
}

void pop(int *stack) {
    if (isEmpty()) {
        printf("\nStack Underflow\n");
        return;
    }
    int item = *stack;
    printf("\nPopped %d from stack\n", item);
    top--;
}

void push(int *stack) {
    if (isFull()) {
        printf("\nStack Overflow\n");
        return;
    }

    printf("\nEnter Number - ");
    scanf("%d", stack++);

    top++;

}

void peek(int *stack) {
    if (isEmpty()) {
        printf("Empty Stack\n");
        return;
    }
    printf("Top Element - %d\n", *stack);

}

int printInstructions() {
    int choice = 0;
    printf("Enter 1 to add to Stack"
           "\nEnter 2 to remove top element from stack"
           "\nEnter 3 to peek at top element of stack"
           "\nEnter 4 to close program"
           "\n->");
    scanf("%d", &choice);
    return choice;
}
