//
// Created by nishu on 14-03-2023.
//
#include <stdio.h>
#include <stdlib.h>


//  Program to show how linked lists work
//  and the types of commands you can do on a linked list

struct Node{
    int value;
    struct Node *next;
};

struct Node *head;


void display();
void recursive(struct Node *p);
void addToFront();
void printList();
void addToLast();
void addBefore();
void addAfter();
void addAtIndex();


void main(){

    // head->next = NULL;
    int opt = 0;
    int newValue;


    while(opt != 9){
        printf("\n\tEnter\n\t1 to add in the front of the list ");
        printf("\n\t2 to add to the back of the list");
        printf("\n\t3 to add before an existing element in the list");
        printf("\n\t4 to add after an existing element in the list");
        printf("\n\t5 to add at a specific index in the list");
        printf("\n\t8 to print the list");
        printf("\n\tEnter 9 to Exit");
        printf("\n ->\t");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                addToFront();
                break;
                break;
            case 2:
                addToLast();
                break;

            case 3:
                addBefore();
                break;
            case 4:
                addAfter();
                break;
            case 5:
                addAtIndex();
                break;

            case 8:
//                printList();
//                display(head);
                display();

            case 9:
            default:
                break;
        }
    }

}

void addToFront(){

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int item;

    if (newNode == NULL){
        printf("OVERFLOW");
    }else{

        printf("Enter New Value  - ");
        scanf("%d", &item);
        newNode -> value = item;
        newNode->next = head;
        head = newNode;
    }
}

void addToLast(){

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int item;
    if (head == NULL){
        addToFront();
        return;
    }

    if (newNode == NULL){
        printf("OVERFLOW");
    }else{
        printf("Enter New Value - ");
        scanf("%d", &item);

        newNode->value = item;
        struct Node *curr;
        curr = head;
        while (curr->next != NULL){
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->next = NULL;
    }
}


void display()
{
    struct Node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("HEAD <-> ");
        while (ptr!=NULL)
        {
            printf("%d <-> ",ptr->value);
            ptr = ptr -> next;
        }
        printf("NULL\n");
    }
}

void addBefore(){
    struct Node * newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    int item, valueOfNext;

    if (head == NULL){
        addToFront();
        return;
    }

    if (newNode == NULL){
        printf("OVERFLOW");
    }else{
        printf("Enter Value - ");
        scanf("%d", &item);
        newNode -> value = item;

        struct Node *curr;
        curr = head;

        display();

        printf("Enter value to put before - ");
        scanf("%d", &valueOfNext);
        if (head->value == valueOfNext){
            newNode->next = head;
            head = newNode;
        }else{
            while (curr->next->value != valueOfNext){
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }

        display();
    }

}

void addAfter(){
    if (head == NULL){
        addToFront();
        return;
    }

    struct Node *newNode, *curr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int item, valueOfBefore;

    if (newNode == NULL){
        printf("OVERFLOW");
    }else{
        curr = head;
        display();
        printf("Enter Value to put after - ");
        scanf("%d", &valueOfBefore);

        while (curr->value != valueOfBefore){
            curr = curr -> next;
        }

        printf("Enter Value - ");
        scanf("%d", &newNode->value);
        newNode->next = curr->next;
        curr->next = newNode;

    }

}

void addAtIndex(){
    struct Node *newNode, *curr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int item, index = 0, indexToAdd;

    if (head == NULL){
        printf("Empty List");
    }else{
        curr = head;
        while(curr->next != NULL){
            index++;
            curr = curr->next;
        }

        printf("Index of List - %d", (index+1));
        printf("\nWhere do you want to add the new element?");
        printf("\n ->");
        scanf("%d", &indexToAdd);

        if (indexToAdd > (index + 1)){
            printf("Error");
        }else{

            printf("Enter Value - ");
            scanf("%d", &newNode->value);
            newNode->next = curr->next;
            curr->next = newNode;
        }

    }
}
