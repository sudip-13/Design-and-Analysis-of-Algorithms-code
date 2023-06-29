#include<stdio.h>
#include<stdlib.h>
void strassens_matrix(int ar1[][10],int ar2[][10],int rc){
    int C[rc][rc],m1,m2,m3,m4,m5,m6,m7;
    m1=(ar1[0][0]+ar1[1][1])*(ar2[0][0]+ar2[1][1]);
    m2=(ar1[1][0]+ar1[1][1])*ar2[0][0];
    m3=(ar1[0][0])*(ar2[0][1]-ar2[1][1]);
    m4=(ar1[1][1])*(ar2[1][0]-ar2[0][0]);
    m5=(ar1[0][0]+ar1[0][1])*ar2[1][1];
    m6=(ar1[1][0]-ar1[0][0])*(ar2[0][0]+ar2[0][1]);
    m7=(ar1[0][1]-ar1[1][1])*(ar2[1][0]+ar2[1][1]);
    C[0][0]=m1+m4-m5+m7;
    C[0][1]=m3+m5;
    C[1][0]=m2+m4;
    C[1][1]=m1-m2+m3+m6;
    printf("After strassens matrix multiplication result will be:-\n");
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
void main(){
    int rc,m[10][10],m1[10][10];
    printf("Enter no of row and column");
    scanf("%d",&rc);
    printf("Enter element in matrix1:-\n");
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("m1[%d][%d]=",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
    printf("Enter element in matrix2:-\n");
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("m2[%d][%d]=",i+1,j+1);
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Matrix1:-\n");
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("Matrix2:-\n");
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("%d\t",m1[i][j]);
        }
        printf("\n");
    }
    strassens_matrix(m,m1,rc);
}