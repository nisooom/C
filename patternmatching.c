#include <stdio.h>

void num_pyramind();
void print_instructions();


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
			default:
				printf("Oops Try Again\n");
				break;
		}
	}
	

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
			printf("%2d", j+1);
		}
		printf("\n");


	}

	
}

void print_instructions() {
	
	printf("Enter 1 for Number Pyramind\n");
	printf("->");

	
}

