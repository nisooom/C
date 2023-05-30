//
// Created by nishu on 30-05-2023.
//

#include "stdio.h"

#if 0
int fac(int x){
    int fac = 1;
    for (int i = 1; i < x; i++){
        fac *= i;
    }
    return fac;
}

int main(){

    int n, i, sum = 0;
    printf("\nEnter N: ");
    scanf("%d", &n);

    for (i = 1; i < n+1; i++){
        sum += (1/(fac(i) + 1));
    }

    printf("\nSum = %d", sum);
    return 1;
}
int main(){

    int count = 0, sum = 0, prod = 1, n;

    printf("\nEnter N: ");
    scanf("%d", &n);

    while(n != 0){
        int p = n%10;
        sum += p;
        prod *= p;
        count++;
        n /= 10;
    }

    printf("\nSum = %d", sum);
    printf("\nCount = %d", count);
    printf("\nProd = %d", prod);

    return 1;
}

#endif

typedef struct {
    char name[256];
    char country[256];
    int matches_played;
    int goal_scored;
}Hockey;

int main(){
    int i, n;

    printf("\nEnter N:");
    scanf("%d", &n);

    Hockey  list[n];

    for (i = 0; i< n; i++){
        Hockey player;
        printf("\nEnter Name - ");
        scanf("%100s", player.name);
        printf("\nEnter Country - ");
        scanf("%100s", player.country);
        printf("\nEnter Matches Played - ");
        scanf("%d", &player.matches_played);
        printf("\nEnter Goals Scored - ");
        scanf("%d", &player.goal_scored);

    }

    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j].goal_scored < list[j + 1].goal_scored) {  // Compare adjacent elements
                // Swap the elements
                Hockey temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("Players in descending order wrt Goals scored - \n");
    for (i = 0; i< n; i++){

        printf("\nName - %s", list[i].name);
        printf("\nCountry - %s", list[i].country);
        printf("\nMatches Played - %d", list[i].matches_played);
        printf("\nGoals Scored - %d", list[i].goal_scored);

    }



}
