//
// Created by nishu on 27-02-2023.
//

#include <stdio.h>

void deQ(int *Q);
void enQ(int *Q);
void display(int *Q);
int printInstructions();
int isEmpty();
int isFull();

int front = -1, rear = -1;
int maxsize;


int main(){

    printf("Enter Length of Stack -  ");
    scanf("%d", &maxsize);

    int queue[maxsize], choice = 0;

    while (choice != 4) {
        choice = printInstructions();
        switch (choice) {
            case 1:
                enQ(queue);
                break;
            case 2:
                deQ(queue);
                break;
            case 3:
                display(queue);
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

int isEmpty(){
    return (front == -1 && rear == -1) || rear < front ? 1 : 0;
}

int isFull(){
    return rear == maxsize - 1 ? 1 : 0;
}

void deQ(int *Q){
    // Removing Elements from Queue
    if (isEmpty()){
        printf("Stack Underflow");
    } else{
        printf("Removed %d from Queue\n", *(Q + front));
        front++;
    }
}

void enQ(int *Q){
    // Adding Element to Queue
    if (isFull()){
        printf("Stack Overflow");
    }else{
        int item;
        printf("\nEnter Element to add - ");
        scanf("%d", &item);

        isEmpty() ? rear=0, front=0 : rear++;
        *(Q+ rear) = item;

    }

}

void display (int *Q){
    for (int i = front; i <= rear; i++){
        printf(" %d, ", *(Q+i));
    }
    printf("\n");
}

int printInstructions() {
    int choice = 0;
    printf("Enter 1 to Enqueue element to Queue"
           "\nEnter 2 to Dequeue element to Queue"
           "\nEnter 3 to Display Queue"
           "\nEnter 4 to close program"
           "\n->");
    scanf("%d", &choice);
    return choice;
}
