//
// Created by nishu on 01-06-2023.
//

#include "stdio.h"

void toh(int N, char dest, char start, char aux){

    if (N == 1){
        printf("Move Disk from %c to %c\n", start, dest);
    }else{
        toh(N-1, aux, start, dest);
        printf("Move Disk %d: %c to %c\n", N, start, dest);
        toh(N-1, dest, aux, start);
    }

}

int main(){
    int n;
    printf("Enter N - ");
    scanf("%d", &n);

    toh(n, 'd', 's', 'a');
}