//
// Created by nishu on 12-12-2022.
//

#include <stdio.h>

void main(){
    int salary;
    float final_salary;

    printf("Enter Salary - ");
    scanf("%d", &salary);

    final_salary = salary + (salary * 0.5) + (salary *0.4);
    printf("Final Salary - %0.2f", final_salary);
}