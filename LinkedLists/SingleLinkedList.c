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
struct Node *newNode;
struct Node *curr;
struct Node *ptr;


void display();
void addToFront();
void addToLast();
void addBefore();
void addAfter();
void addAtIndex();
void removeFromFirst();
void removeFromLast();
int printInstructions();
int printInstructions_creation();
int printInstructions_deletion();
void removeSpecific();

int printInstructions(){
    int opt, finalOpt;

    printf("\n\tEnter");
    printf("\n\t1 to add a node");
    printf("\n\t2 to remove a node");
    printf("\n\t3 to print the linked list");
    printf("\n\t4 to Exit");
    printf("\n ->\t");
    scanf("%d", &opt);

    switch(opt){
        case 1:
            printInstructions_creation();
            break;
        case 2:
            printInstructions_deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            return 4;
        default:
            break;
    }

    return 0;
}

int printInstructions_creation(){
    int opt;

    printf("\n\t1 to add in the front of the list ");
    printf("\n\t2 to add to the back of the list");
    printf("\n\t3 to add before an existing element in the list");
    printf("\n\t4 to add after an existing element in the list");
    printf("\n\t5 to add at a specific index in the list");
    printf("\n->");
    scanf("%d", &opt);

    switch(opt){
        case 1:
            addToFront();
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
        default:
            break;
    }

    return 0;
}

int printInstructions_deletion(){
    int opt;
    printf("\n\t1 to remove node from the start of the list");
    printf("\n\t2 to remove node from the end of the list");
    printf("\n\t3 to remove specific node from the list");
    printf("\n->");
    scanf("%d", &opt);

    switch(opt){
        case 1:
            removeFromFirst();
            break;
        case 2:
            removeFromLast();
            break;
        case 3:
            removeSpecific();
            break;
        default:
            break;
    }
    return opt;
}

void main(){

    // head->next = NULL;
    int opt = 0;
    int newValue;

    while(opt != 4){
        opt = printInstructions();
    }

}

void addToFront(){

    newNode = (struct Node*)malloc(sizeof(struct Node));

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

    newNode = (struct Node*)malloc(sizeof(struct Node));

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

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL){
        addToFront();
        return;
    }

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

//    newNode = (struct Node*)malloc(sizeof(struct Node));
//
//    int item, index = 0, indexToAdd;
//
//    if (head == NULL){
//        printf("Empty List");
//    }else{
//        curr = head;
//        while(curr->next != NULL){
//            index++;
//            curr = curr->next;
//        }
//
//        printf("Index of List - %d", (index+1));
//        printf("\nWhere do you want to add the new element?");
//        printf("\n ->");
//        scanf("%d", &indexToAdd);
//
//        if (indexToAdd > (index + 1)){
//            printf("Error");
//        }else{
//
//            printf("Enter Value - ");
//            scanf("%d", &newNode->value);
//            newNode->next = curr->next;
//            curr->next = newNode;
//        }
//
//    }
}

void removeFromFirst(){
    if (head == NULL){
        printf("Empty List");
        return;
    }

    int valueRemoved = head->value;
    head = head->next;
    printf("\nRemoved %d\n", valueRemoved);

}

void removeFromLast(){

    if (head == NULL){
        printf("Empty List");
        return;
    }

    int valueRemoved;
    curr = head;

    while(curr->next->next != NULL){
        curr = curr->next;
    }
    valueRemoved = curr->next->value;
    curr->next = NULL;

    printf("\nRemoved %d\n", valueRemoved);
}

void removeSpecific(){
    int valueToRemove;
    curr = head;
    display();

    printf("Enter value to remove - ");
    scanf("%d", &valueToRemove);

    while (curr->next->value != valueToRemove){
        curr = curr->next;
    }

    valueToRemove = curr->next->value;

    curr->next = curr->next->next;
    printf("Node removed - %d\n", valueToRemove);
    display();
}