#include<stdio.h>
#include<stdlib.h>
void matrix_mul(int ar1[][10],int ar2[][10],int r,int c,int r1,int c1){
    int C[10][10];
    for(int i=0;i<r;i++){
        for(int j=0;j<c1;j++){
            C[i][j]=0; 
            for(int k=0;k<c;k++){
                C[i][j]+=ar1[i][k]*ar2[k][j];
            }
        }
    }
    printf("Result of matrix multiplication is:-\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c1;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
void main(){
    int r,c,r1,c1,m[10][10],m1[10][10];
    printf("Enter no of row  and column for matrix1");
    scanf("%d %d",&r,&c);
    printf("Enter no of row  and column for matrix2");
    scanf("%d %d",&r1,&c1);
    printf("Enter element in matrix1\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("m1[%d][%d]= ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
    printf("Enter element in matrix2\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("m2[%d][%d]= ",i+1,j+1);
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Matrix1:-\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("Matrix2:-\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("%d\t",m1[i][j]);
        }
        printf("\n");
    }
    matrix_mul(m,m1,r,c,r1,c1);
}