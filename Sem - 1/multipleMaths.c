#include <stdio.h>
#include <string.h>
#include <math.h>


int isPrime(int n)
{
    // Check if n=1 or n=0
    if (n <= 1)
        return 0;
    // Check if n=2 or n=3
    if (n == 2 || n == 3){
        return 1;
	}else{
		for(int i = 3; i < n; i++){
			if (n%i==0){
				return 0;
				break;
			}
		}
		return 1;
	}
}

void main()
{
    int n, opt;
    printf("Enter Number - ");
    scanf("%d", &n);

	printf("\nEnter 1 for finding square root\nEnter 2 for finding square\nEnter 3 for finding cube\nEnter 4 for finding Factorial\nEnter 5 to check if number is prime or not\n->");
	scanf("%d", &opt);

	int sq, cb, sum;
	double sr;
	switch (opt)
	{
	case 1:
    	sr = sqrt(n);
    	printf("the square root is = %.3f \n", sr);

		break;
	case 2:
 		sq = n * n;
   		printf("the square is = %d\n", sq);

		break;
	case 3:
		cb = n * n * n;
    	printf("the cube is = %d\n", cb);
		break;
	case 4:
		sum = 1;
    
		for (int i = 1; i < n + 1; i++)
    	{
        	sum = sum * i;
    	}

	    printf("the factorial is - %d\n", sum);
	case 5:
    	if (isPrime(n) == 1){
        	printf("the number is a prime number\n");
		}else{
        	printf("the number isnt prime\n");
		}
		break;
	default:
		break;
	}

}
