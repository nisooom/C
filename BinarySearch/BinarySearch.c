//
// Created by nishu on 12-04-2023.
//

#include <stdio.h>

int array[] = {3,9,24,35,67,80,85,91,92,98};

int BSearch(int inputArray[], int begin, int end, int search){

    int mid;

    if (begin > end){
        return 0;
    }

    mid = (begin+end)/2;

    if (inputArray[mid] == search) return 1;

    if (search > inputArray[mid]){
        BSearch(inputArray, mid+1, end, search);
    }
    if (search < inputArray[mid]){
        BSearch(inputArray, begin, mid, search);
    }
}


int main(void){

    int x = BSearch(array, 0, 10, 40);

    if (x){
        printf("Found");
    }else{
        printf("Not Found");
    }

    return 2;
}