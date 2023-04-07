//
// Created by nishu on 06-04-2023.
//
#if 1
#include <stdio.h>
#include <stdlib.h>
#endif

typedef struct branch{
    int value;
    struct branch *left;
    struct branch *right;
}branch;

branch *root;
branch *newBranch;
branch *curr;

branch* createNewBranch();
void addBranch();
void print();
void printInstructions();

branch* createNewBranch() {
    newBranch = (branch *) malloc(sizeof(branch));
    printf("Enter Value - ");
    scanf("%d", &newBranch->value);

    if (newBranch == NULL){
        printf("Overflow");
        return NULL;
    }

    newBranch -> left = NULL;
    newBranch -> right = NULL;
    return newBranch;
}

void addBranch(){
    newBranch = createNewBranch();
    if (newBranch == NULL) {
        printf("Error Occurred");
        return;
    }

    if (root == NULL){
        printf("Initialized Tree with new root - %d", newBranch->value);
        root = newBranch;
        return;
    }

    curr = root;
    branch *previous = curr;

//  Loop to reach the last point where to add the new branch
    while (curr != NULL){
        previous = curr;
        if (newBranch->value > curr->value){
            curr = curr->right;
        }else {
            curr = curr->left;
        }
    }

//  Adding the value after finding the last branch.

    (newBranch->value > previous->value) ? (previous -> right = newBranch) : (previous->left = newBranch);
    printf("New branch added = %d", newBranch->value);
//    if (newBranch->value > previous->value){
//        previous -> right = newBranch;
//    }else{
//        previous -> left = newBranch;
//    }

}

void printInOrder(branch *pBranch){
    if (pBranch == NULL)
    {
        return;
    }
    printInOrder(pBranch->left);
    printf("%d ", pBranch->value);
    printInOrder(pBranch->right);
}

void printInstructions(){
    printf("\nEnter 1 to add node to branch");
    printf("\nEnter 2 to printInOrder tree");
    printf("\nEnter 3 to quit");
}

void loopMain(){
    int option = 0;

    do {
        printInstructions();
        printf("\n\t-> ");
        scanf("%d", &option);

        switch(option){
            case 1:
                addBranch();
                break;
            case 2:
                printInOrder(root);
                break;
            case 3:
                exit(0);
            default:
                break;
        }

    }while (option != 3);


}

int main(){

    loopMain();

    return 1;
}
