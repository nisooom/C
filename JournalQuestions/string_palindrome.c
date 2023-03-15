#include <stdio.h>
#include <string.h>

void check_palindrome();

void main()
{
    char checkpalindrome[100];
    printf("Enter word - ");
    scanf("%s", &checkpalindrome);

    check_palindrome(checkpalindrome);
}

void check_palindrome(char word[])
{
    int size = strlen(word);

    for (int i = 0; i < (size / 2); i++)
    {
        for (int j = size; j > (size / 2); j--)
        {
            printf(" %s \t\t %s \n", word[i], word[j]);
        }
    }
}