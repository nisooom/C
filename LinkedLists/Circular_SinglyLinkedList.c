//
// Created by nishu on 24-03-2023.
//
#include <stdlib.h>
#include "stdio.h"


typedef struct node{
    int value;
    struct node *next;
}node;

node *head = NULL;
node *curr;
node *newNode;

node* init();
void addToFront();
void addToLast();
void printList();

int main(){
    int opt = 0;

    while (opt!= 9){
        printf("\nEnter 1 to add to front of the list");
        printf("\nEnter 2 to add to the end of the list");
        printf("\nEnter 3 to print the list");
        printf("\nEnter 9 to exit");
        printf("\n\t->");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                addToFront();
                break;
            case 2:
                addToLast();
                break;
            case 3:
                printList();
                break;
            case 9:
                opt = 9;
                break;
            default:
                break;
        }
    }

    return 0;
}

node* init(){
    newNode = (node*)malloc(sizeof (node));

    if (newNode==NULL){
        printf("Overflow");
        return NULL;
    }

    printf("Enter Value - ");
    scanf("%d", &newNode->value);

    return newNode;
}

void addToFront(){
    newNode = init();

    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;
}

void addToLast(){
    newNode = init();

    if (head->next == head){
        head->next = newNode;
        newNode->next = head;
    }else{
        curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = head;
    }
}

void printList() {
    struct node* current = head;

    // Check if the list is empty
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    printf("Circular Linked List: ");

    // Traverse the list until we reach the starting node again
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != head);

    printf("\n");
}