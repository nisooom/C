//
// Created by nishu on 27-03-2023.
//
#include "stdio.h"
#include "stdlib.h"

const int size = 100;
char stack[100];
int top = -1;

int isEmpty(){
    return top == -1 ? 1 : 0;
}

int isFull(){
    return top == size  ? 1 : 0;
}

void pop(){
    if (isEmpty()){
        printf("Empty Stack");
        return;
    }

    char curr = stack[top];
    top--;
}


void push(char x){
    if (isFull()){
        printf("Stack Overflow");
        return;
    }

    if (x == '(' || x == '{' || x == '['){
        stack[top+1] = x;
        top++;
    }else if (x == '(' && (stack[top] == '{' || stack[top] == '[' || stack[top] == '{')){

    }
    else if((x == ')' && stack[top] == '(') || (x == ']' && stack[top] == '[') || (x == '}' && stack[top] == '{') ){
        pop();
    }else{
        printf("Error occurred the parenthesis arent in order");
        exit(1);
    }
}

int main(){
    int opt;
    char p_list[size];
    printf("Enter Parenthesis - ");
    scanf("%[^\n]%*c", p_list);

    for (int i = 0; i < (sizeof (p_list)/ sizeof(p_list[0])); i++){
        push(p_list[i]);
    }




    return 0;
}

