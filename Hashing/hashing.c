//
// Created by nishu on 19-04-2023.
// Hashing Functions
//

#include "stdio.h"
#include "stdlib.h"

#define HASHSIZE 10
#define EXITCHOICE 5

int hashTable[HASHSIZE] = {0};
int sizeList = 0;

int hash(int value);
void addValue(int value);
void printValues();
void searchValue(int value);
int printInstructions();
void removeValue(int value);

int printInstructions() {
    int choice;
    printf("\nEnter 1 to Add"
           "\nEnter 2 to Print"
           "\nEnter 3 to Search"
           "\nEnter 4 to Remove"
           "\nEnter 5 to Exit"
           "\n->");
    scanf("%d", &choice);
    return choice;
}

int main(){
    int choice = 0;
    while (choice != EXITCHOICE) {
        int val;
        choice = printInstructions();
        switch (choice) {
            case 1:
                printf("Enter Number - ");
                scanf("%d", &val);
                addValue(val);
                break;
            case 2:
                printValues();
                break;
            case 3:
                printf("Enter Number - ");
                scanf("%d", &val);
                searchValue(val);
                break;
            case 4:
                printf("Enter Number - ");
                scanf("%d", &val);
                removeValue(val);
                break;
            case EXITCHOICE:
                choice = EXITCHOICE;
                break;
            default:
                break;
        }
    }

    return 1;
}

int hash(int value){
    return value % HASHSIZE;
}

void addValue(int value){

    if (sizeList == HASHSIZE){
        printf("LIST FULL\n");
        return;
    }


    int key = hash(value);
    int tmpkey = key+1;

    if (hashTable[key] == 0){
        hashTable[key] = value;
        sizeList++;
    } else {
        while (1){
            if (tmpkey >= HASHSIZE){
                tmpkey = 0;
            }
            if (hashTable[tmpkey] != 0){
                tmpkey++;
            }else{
                hashTable[tmpkey] = value;
                sizeList++;
                break;
            }
        }
    }
}

void printValues(){
    printf("\n");

    for (int i = 0; i < HASHSIZE; i++){
        printf("%d\t:\t", i+1);
        if (hashTable[i] == 0) {
            printf("-NULL-\n");
        } else{
            printf("%d\n", hashTable[i]);
        }
    }
    printf("\n");

}

void searchValue(int value){
    int key = hash(value);
    int tmpk = key+1;

    if (hashTable[key] == value){
        printf("%d found in table\n", value);
        return;
    }else{
        while (1){
            if (tmpk == key) {
                break;
            }

            if (tmpk == HASHSIZE){
                tmpk = 0;
            }

            if (hashTable[tmpk] == value){
                printf("%d found in table\n", value);
                return;
            }else{
                tmpk++;
            }
        }
    }

    printf("%d not found in table\n", value);

}

void removeValue(int value){
    int key = hash(value);
    int tmpk = key+1;

    if (sizeList == 0){
        printf("List Empty\n");
        return;
    }

    if (hashTable[key] == value){
        printf("%d Removed\n", value);
        hashTable[key] = 0;
        return;
    }else{
        while (1){
            if (tmpk == key) {
                break;
            }

            if (tmpk == HASHSIZE){
                tmpk = 0;
            }

            if (hashTable[tmpk] == value){
                printf("%d Removed\n", value);
                hashTable[key] = 0;
                return;
            }else{
                tmpk++;
            }
        }
    }

    printf("Error Occurred, %d not found", value);
}
