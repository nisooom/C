//
// Created by nishu on 24-05-2023.
//

#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int val;
    struct Node * next;
}Node;

Node *head = NULL;
Node *newNode ;
Node *ptr;

void createNode(){
    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Node Error");
        return;
    }else{
        printf("Enter value of new node - ");
        scanf("%d", &newNode->val);
        newNode->next = NULL;
    }
}

void addToFront(){
    createNode();

    if (head != NULL){
        newNode->next = head;
    }

    head = newNode;
}

void addToEnd(){
    createNode();

    ptr = head;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = newNode;
}

void addBefore(){
    createNode();

    int node_val;
    printf("Enter node to add before - ");
    scanf("%d", &node_val);

    ptr = head;

    while(ptr->next->val != node_val){
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;

}

void addAfter(){
    createNode();

    int node_val;
    printf("Enter node to add after - ");
    scanf("%d", &node_val);

    ptr = head;

    while(ptr->val != node_val){
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;

}

void removeFromFirst(){
    if (head == NULL){
        printf("Empty List");
        return;
    }

    int valRem = head->val;

    Node * rem = head;
    head = head->next;

    free(rem);
}

void removeFromLast(){
    if (head == NULL){
        printf("Empty List");
        return;
    }

    ptr = head;
    while(ptr->next->next != NULL) ptr=ptr->next;

    Node * rem = ptr->next;
    ptr->next = NULL;

    free(rem);
}

void removeSpec(){
    int node_val;
    printf("\nEnter Value to remove - ");
    scanf("%d", &node_val);

    ptr = head;

    while(ptr->next->val != node_val) ptr = ptr->next;

    Node * rem = ptr->next;
    ptr->next = ptr->next->next;
    free(rem);

    printf("%d removed!", node_val);
}

void display(){
    ptr = head;

    printf("[\n");
    while (ptr!= NULL){
        printf("\t%d\n", ptr->val);
        ptr = ptr->next;
    }
    printf("]\n");
}

int main() {
    int opt = 0;

    while (opt != -1) {
        printf("\n\t1 Add node at start");
        printf("\n\t2 Add node at end");
        printf("\n\t3 Add node before");
        printf("\n\t4 Add node after");
        printf("\n\t5 Remove first node");
        printf("\n\t6 Remove last node");
        printf("\n\t7 Remove specific node");
        printf("\n\t8 Display");
        printf("\n\t9 Exit");


        printf("\n->");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                addToFront();
                break;
            case 2:
                addToEnd();
                break;
            case 3:
                addBefore();
                break;
            case 4:
                addAfter();
                break;
            case 5:
                removeFromFirst();
                break;
            case 6:
                removeFromLast();
                break;
            case 7:
                removeSpec();
                break;
            case 8:
                display();
                break;
            case 9:
                opt = -1;
                break;
            default:
                break;
        }

    }
}

