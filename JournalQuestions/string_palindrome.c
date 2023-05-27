#include <stdio.h>
#include <string.h>

void check_palindrome();

void main()
{
    char *checkpalindrome = NULL;
    printf("Enter word - ");
    scanf("%c", checkpalindrome);

    check_palindrome(checkpalindrome);
}

void check_palindrome(char *word)
{
    int size = strlen(word);

    for (int i = 0; i < (size / 2); i++)
    {
        for (int j = size; j > (size / 2); j--)
        {
            printf(" %c \t\t %c \n", word[i], word[j]);
        }
    }
}

int findLength(char *word){
    int i = 0;

    while (word[i] != '\0'){
        i++;

    }

    return i;
}