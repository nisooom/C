#include <stdio.h>

void main()
{
    float a, b, c, root1, root2;

    // Get the values for A,B,C
    printf("Form of Equation - Ax^2 + Bx + c = 0");
    printf("\nA = ");
    scanf("%f", &a);
    printf("\nB = ");
    scanf("%f", &b);
    printf("\nC = ");
    scanf("%f", &c);

    // Find determinant, if less than 0, no roots for the equation.
    float det = (b * b) - 4 * a * c;
    if (det < 0)
    {
        printf("There are no roots of this equation");
    }
    else
    {
        float det_root = sqrt(det);

        // Formula = -b +- root(det)/ 2a

        root1 = ((b * -1) + det_root) / 2 * a;
        root2 = ((b * -1) - det_root) / 2 * a;

        printf("Roots of this Equation (%0.0fx^2 +(%0.0f)x + (%0f)) are - \n -> %0.2f \n -> %0.2f", a, b, c, root1, root2);
    }
}