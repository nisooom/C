//
// Created by nishu on 15-07-2023.
//

#include <stdio.h>

int main1(){

    int x;
    char *c = "";
    float f;

    printf("Enter Integer - ");
    scanf("%d", &x);

    printf("Enter String - ");
    scanf("%c", c);

    printf("Enter Float - ");
    scanf("%f", &f);

    printf("\nInteger - %d", x);
    printf("\nString - %s", c);
    printf("\nFloat - %f", f);

    return 1;
}

int main2(){
    int x,y;

    printf("Enter X - ");
    scanf("%d", &x);

    printf("Enter Y - ");
    scanf("%d", &y);


    printf("\n X + Y = %d", (x+y));
    return 1;
}

int main3(){

    int x;
    printf("Enter X - ");
    scanf("%d", &x);

    if (x % 2 == 0){
        printf("%d is EVEN", x);
    } else{
        printf("%d is ODD", x);
    }


    return 1;

}

int main4(){

    int x,y;

    printf("Enter X - ");
    scanf("%d", &x);

    printf("Enter Y - ");
    scanf("%d", &y);

    printf("\n X - %d\nY = %d", x,y);

    printf("\nAfter Swap");

    int tmp = x;
    x = y;
    y = tmp;

    printf("\n X - %d\nY = %d", x,y);

    return 1;
}

int main(){
    int x, i, fact = 1;
    printf("Enter X - ");
    scanf("%d", &x);

    for (i = 1; i <= x; i++){
        fact *= i;
    }

    printf("Factorial of %d = %d", x, fact);

    return 1;
}