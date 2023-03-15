#include <stdio.h>

void num_pyramind();

void print_instructions();

void star_pascal();

void reverse_pascal();

void main()
{
	int opt, i = 0;

	while (i == 0)
	{

		print_instructions();
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			num_pyramind();
			i = -1;
			break;
		case 2:
			star_pascal();
			i = -1;
			break;
		case 3:
			reverse_pascal();
			i = -1;
			break;
		default:
			printf("Oops Try Again\n");
			break;
		}
	}
}

void print_instructions()
{

	printf("Enter 1 for Number Pyramind\n");
	printf("Enter 2 for Star Pascal Pattern\n");
	printf("Enter 3 for Reverse Star Pascal Pattern\n");

	printf("->");
}
void num_pyramind()
{
	// 1
	// 1 2
	// 1 2 3
	// 1 2 3 4
	printf("Enter number of rows -> ");
	int rows;
	scanf("%d", &rows);
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%4d", j + 1);
		}
		printf("\n");
	}
}

void star_pascal()
{

	printf("Enter number of rows -> ");
	int rows;
	scanf("%d", &rows);

	for (int i = 0; i < rows; i++)
	{
		for (int spaces = 1; spaces <= rows - i; spaces++)
		{
			printf(" ");
		}

		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}

		printf("\n");
	}
}

void reverse_pascal()
{
	int rows, i, j, spaces;
	printf("Enter Number of rows ->");
	scanf("%d", &rows);

	for (i = rows; i >= 1; i--)
	{
		for (spaces = 0; spaces < rows; spaces++)
		{
			printf(" ");
		}
		for (j = i; j <= 2 * i - 1; j++)
		{
			printf("*");
		}

		for (j = 0; j < i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
