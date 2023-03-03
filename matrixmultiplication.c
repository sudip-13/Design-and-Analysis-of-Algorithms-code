#include <stdio.h>
#include <stdlib.h>
void matrix_mul()
{
    int i, j, k;
    int ar1[10][10], ar2[10][10], c[10][10], r1, r2, c1, c2;
    printf("enter no of row of matrix1");
    scanf("%d", &r1);
    printf("enter no of column of matrix1");
    scanf("%d", &c1);
    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c1; j++)
        {
            printf("ar1[%d][%d]", i + 1, j + 1);
            scanf("%d", &ar1[i][j]);
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d\t", ar1[i][j]);
        }
        printf("\n");
    }
    printf("enter no of row of matrix2");
    scanf("%d", &r2);
    printf("enter no of column of matrix2");
    scanf("%d", &c2);
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("ar2[%d][%d]", i + 1, j + 1);
            scanf("%d", &ar2[i][j]);
        }
    }
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", ar2[i][j]);
        }
        printf("\n");
    }
    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible");
    }
    else
    {
        // for (i = 0; i < r1; ++i)
        // {
        //     for (j = 0; j < c2; ++j)
        //     {
        //         c[i][j]=0;
        //     }
        // }
        int sum=0;
        for (i = 0; i < r1; ++i)
        {
            for (j = 0; j < c2; ++j)
            {
                sum=0;
                for (k = 0; k < c1; ++k)
                {
                    sum += ar1[i][k] * ar2[k][j];
                }
                c[i][j] = sum;
            }
        }
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
}
    void main()
    {
        matrix_mul();
    }