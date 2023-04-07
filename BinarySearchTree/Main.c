//
// Created by nishu on 06-04-2023.
//

#include <stdio.h>
#include <stdlib.h>

// Define a branch data structure
typedef struct branch {
    int value;
    struct branch *left;
    struct branch *right;
} branch;

// Declare global variables
branch *root; // Root of the binary search tree
branch *newBranch; // Pointer to a new branch that will be created
branch *curr; // Current branch when traversing the tree

// Create a new branch with user input value
branch *createNewBranch() {
    newBranch = (branch *) malloc(sizeof(branch)); // Allocate memory for the new branch
    printf("Enter Value - ");
    scanf("%d", &newBranch->value);

    // If the new branch is NULL, there is an overflow error
    if (newBranch == NULL) {
        printf("Overflow");
        return NULL;
    }

    // Set left and right pointers of the new branch to NULL
    newBranch->left = NULL;
    newBranch->right = NULL;
    return newBranch;
}

// Add a new branch to the binary search tree
void addBranch() {
    newBranch = createNewBranch(); // Create a new branch
    if (newBranch == NULL) { // If there is an error creating the new branch, exit the function
        printf("Error Occurred");
        return;
    }

    // If the root is NULL, initialize the tree with the new root
    if (root == NULL) {
        printf("Initialized Tree with new root - %d", newBranch->value);
        root = newBranch;
        return;
    }

    // Traverse the tree to find the last point where to add the new branch
    curr = root;
    branch *previous = curr;

    while (curr != NULL) {
        previous = curr;
        if (newBranch->value > curr->value) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    // Add the value after finding the last branch
    (newBranch->value > previous->value) ? (previous->right = newBranch) : (previous->left = newBranch);

    // One-liner if statement for above code
    // if (newBranch->value > previous->value){
    //     previous -> right = newBranch;
    // } else {
    //     previous -> left = newBranch;
    // }

    printf("New branch added = %d", newBranch->value);
}

// Print the tree in-order traversal
void printInOrder(branch *b) {
    if (b == NULL) { // If the tree is empty, print a message and exit the function
        printf("Empty Tree");
        return;
    }

    // Traverse the left subtree
    printInOrder(b->left);

    // Print the current node
    printf("%d ", b->value);

    // Traverse the right subtree
    printInOrder(b->right);
}

// Print the tree pre-order traversal
void printPreOrder(branch *b) {
    if (b == NULL) { // If the tree is empty, print a message and exit the function
        printf("Empty Tree");
        return;
    }

    // Print the current node
    printf("%d ", b->value);
    // Traverse the left subtree
    printPreOrder(b->left);
    // Traverse the right subtree
    printPreOrder(b->right);
}

// Print the tree post-order traversal
void printPostOrder(branch *b) {
    if (b == NULL) {
        printf("Empty Tree");
        return;
    }
//    Traverse the sub trees
    printPostOrder(b->left);
    printPostOrder(b->right);
//    print current branch value
    printf("%d ", b->value);

}

void printInstructions() {
    printf("\nEnter 1 to add node to branch");
    printf("\nEnter 2 to printInOrder tree");
    printf("\nEnter 3 to quit");
}

void loopMain() {
//    Just to keep the main function clean

    int option = 0;

    do {
        printInstructions();
        printf("\n\t-> ");
        scanf("%d", &option);

        switch (option) {
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

    } while (option != 3);


}

int main() {

    loopMain();

    return 1;
}
