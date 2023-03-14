#include <stdio.h>
#include <stdlib.h>


//  Program to show how linked lists work 
//  and the types of commands you can do on a linked list



void addToFront();
void printList();
void display();

struct Node{
    int value;
    struct Node *next;
}*head = NULL;


void main(){

    // head->next = NULL;
    int x = 1;
    int opt;
    int newValue;
    

    while(x){
        printf("\nEnter 1 to add");
        printf("\n2 to print list");
        printf("\n ->");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                printf("Enter New Number - ");
                scanf("%d", &newValue);
                addToFront(newValue);
                break;
            case 2:
                // printList();
                display(head);
                break;
            case 3:
                x = 0; 
                break;
        
            default:
                break;
        }
    }

}

void addToFront(int newValue){
    struct Node *newNode; 
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = newValue;
    if (!head){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

// void printList(){
//     Node *curr;
//     curr = head;
//     if (!curr){
//         printf("Empty List");
//     }else{

//         printf("Head\n");
//         while (curr->next != 0){
//             printf(" %d <->", curr->value);
//             curr = curr->next;
//         }
//         printf(" End ");
//     }
// }

void display(struct Node *p)  
{  
    // Node *temp;
    // temp = (Node *)malloc(sizeof(Node));
    while (p != NULL){
        printf(" %d ", p->value);
        p = p->next;
    }

    // printf("%d", head->value);
}     
              