//
// Created by nishu on 17-03-2023.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
}Node;


Node *head;
Node *newNode;
Node *curr;
Node *ptr;


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
    printf("\n\t3 to printInOrder the linked list");
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
//            addAfter();
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
//            removeFromFirst();
            break;
        case 2:
//            removeFromLast();
            break;
        case 3:
//            removeSpecific();
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

void display(){
    curr = head;
    if (head == NULL){
        printf("Empty List");
    }else{
        printf("Head <-> ");
        while(curr != NULL){
            printf("%d <-> ", curr->value);
            curr=curr->next;
        }
        printf("Null\n");
    }
}

void addToFront(){
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Overflow");
    }else{
        printf("Enter Node - ");
        scanf("%d", &newNode->value);
        newNode->prev = NULL;
        if (head == NULL){
            newNode->next = NULL;
            head = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;

            head = newNode;
        }
    }
}

void addToLast(){
    newNode = (Node *) malloc(sizeof(Node));
    curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    printf("Enter Value - ");
    scanf("%d", &newNode->value);
    if (head==NULL){
        newNode = head;
        newNode->prev = NULL, newNode->next = NULL;
    }else{
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = NULL;
    }
}

void addBefore(){
    newNode = (Node*)malloc(sizeof(Node));
    int valueBefore;
    curr = head;

    display();
    printf("Enter value to add before - ");
    scanf("%d", &valueBefore);

    printf("Enter value - ");
    scanf("%d", &newNode->value);


    if (newNode == NULL){
        printf("Overflow");
    }else {
        if (head == NULL) {
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;

        } else {

            while (curr->next->value != valueBefore){
                curr = curr->next;
            }

            curr->next->prev = newNode;
            newNode->prev = curr;
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}