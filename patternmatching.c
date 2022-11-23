#include <stdio.h>

void num_pyramind();
void print_instructions();
void star_pascal();

void main() {
	int opt, i = 0;

	while(i == 0){

		print_instructions();
		scanf("%d", &opt);
	
		switch(opt){
			case 1:
				num_pyramind();
				i = -1;
				break;
			case 2:
				star_pascal();
				i = -1;
				break;
			default:
				printf("Oops Try Again\n");
				break;
		}
	}
	

}

void print_instructions() {
	
	printf("Enter 1 for Number Pyramind\n");
	printf("Enter 2 for Star Pascal Pattern\n");


	printf("->");

}
void num_pyramind(){
	// 1
	// 1 2
	// 1 2 3
	// 1 2 3 4
	printf("Enter number of rows -> ");
	int rows;
	scanf("%d", &rows);
	for (int i = 1; i <= rows; i ++){
		for (int j = 0; j < i; j ++) { 
			printf("%4d", j+1);
		}
		printf("\n");


	}

	
}

void star_pascal(){
	
	printf("Enter number of rows -> ");
	int rows;
	scanf("%d", &rows);
	
	for (int i = 0; i < rows; i ++){
		for (int spaces = 1; spaces <= rows - i; spaces++){

		}

		for (int j = 0; j <= i; j++){
			printf("    *");
		}
	
		printf("\n");
	}

}

	


