#include <stdio.h>
#include <string.h>

typedef struct DateOfJoin
{
    int day, month, year;
} DateOfJoin;

typedef struct Employee
{
    char name[35];
    char designation[35];
    char gender[10];
    DateOfJoin DateOfJoin;
    float salary;

} Employee;

Employee addEmployee();

void printEmployees();

void main()
{

    // to find the length of an array -
    // printf("size of array = %d", sizeof(arr) / sizeof(arr[0]));
    int num_emps, i;
    printf("Enter number of Employees to add - ");
    scanf("%d", &num_emps);
    Employee employeeList[100];
    for (i = 0; i < num_emps; i++)
    {
        employeeList[i] = addEmployee();
    }

    printf("\nNumber of Employees - %d", num_emps);
    printf("\nEmployees with more than 20000 salary - \n");
    for (int i = 0; i < num_emps; i++)
    {
        Employee em = employeeList[i];
        if (em.salary > 20000.00)
        {
            printf("%s\n", em.name);
        }
    }

    char opt[1];
    printf("Do you wish to print all employee info? (y/n) - ");
    scanf("%s", opt);

    if (opt == "y")
    {
        printEmployees(employeeList, num_emps);
    }
}

Employee addEmployee()
{
    Employee em;

    printf("\nEnter Name - ");
    scanf("%99s[^\n]", em.name);

    printf("Enter Designation - ");
    scanf("%s", em.designation);

    printf("Enter Gender - ");
    scanf("%s", em.gender);

    printf("Enter Date of Join (DD MM YYYY) - ");
    scanf("%d%d%d", &em.DateOfJoin.day, &em.DateOfJoin.month, &em.DateOfJoin.year);

    printf("Enter Salary - ");
    scanf("%f", &em.salary);

    return em;
}

void printEmployees(Employee em[], int numEmps)
{
    for (int i = 0; i < numEmps; i++)
    {
        Employee temp = em[i];
        printf("Name: %s\nDesignation: %s\nGender: %s\nDate of Join: %d/%d/%d\nSalary: %d\n\n", temp.name, temp.designation, temp.gender, temp.DateOfJoin.day,
               temp.DateOfJoin.month, temp.DateOfJoin.year, temp.salary);
    }
}