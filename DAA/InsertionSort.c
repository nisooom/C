
//
// Created by nishu on 18-07-2023.
//

#include <stdio.h>

void ins_sort(int *array, int n) {

    int key, i, j;

    for (i = 1; i < n; i++) {

        do {
            key = array[i];
            j = i-1;
        }

    }

}

void arr_print(int *array, int n) {

    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }

}


int main() {
    int array[] = {20, 12, 23, 42, 1, 34, 24, 245};
    int n = 8;

    ins_sort(array, n);


    return 1;
}