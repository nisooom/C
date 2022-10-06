#include <stdio.h>

void printMatrice(int mat[3][3]);

void printInstructions();

void multiplyMatrice(int mat1[3][3], int mat2[3][3]);

void matriceT(int mat1[3][3]);

int matriceAdd(int mat1[3][3], int mat2[3][3])
{
    int finMat[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            finMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printMatrice(finMat);

    return -1;
}

void main()
{
    // first get the 3x3 matrices
    // then ask what to do with them
    // save matrices in nested array

    int matrice1[3][3], matrice2[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\n Enter the i[%d][%d]'th element of the first matrice = ", i + 1, j + 1);
            scanf("%d", &matrice1[i][j]);
        }
    }

    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            printf("\n Enter the i[%d][%d]'th element of the second matrice = ", k + 1, l + 1);
            scanf("%d", &matrice2[k][l]);
        }
    }

    printf("\n\n");

    printf("Matrice 1 - \n");
    printMatrice(matrice1);
    printf("\n Matrice 2 - \n");
    printMatrice(matrice2);

    printf("\n\n\n");

    int opt;

    printInstructions();
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("Addition of Matrix - \n");
        matriceAdd(matrice1, matrice2);
        break;
    case 2:
        printf("Multiplication of Matrix - \n");
        multiplyMatrice(matrice1, matrice2);
        break;
    case 3:
        printf("Transpose of which Matrix is to be found? - ");
        int matOpt;
        scanf("%d", &matOpt);
        switch (matOpt)
        {
        case 1:
            matriceT(matrice1);
            break;
        case 2:
            matriceT(matrice2);
            break;
        default:
            break;
        }
        break;
    default:
        printf("oh oops");
        break;
    }

    // redundant constants just for calling function
    // int a, b;
    // a = printMatrice(matrice1);
    // b = printMatrice(matrice2);
}

void printMatrice(int mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("\n[%d %d %d]\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

void printInstructions()
{
    printf("For Adding the matrices press 1\nFor Multiplying the Matrices press 2 \nFor finding the Transpose of the both of the matrices press 3\n ->");
}

void multiplyMatrice(int mat1[3][3], int mat2[3][3])
{
    int mul[3][3], i, j, k;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printMatrice(mul);
}

void matriceT(int mat1[3][3])
{
    int finalMat[3][3], i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            finalMat[j][i] = mat1[i][j];
        }
    }

    printMatrice(finalMat);
}