#include<stdio.h>
#include<stdlib.h>
void all_pair(int g[][100],int row){
    int i,j,k;
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            for(k=0;k<row;k++){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
}
void main(){
    int ar[100][100],rc,i,j;
    printf("Enter no of row and no of Column");
    scanf("%d",&rc);
    for(i=0;i<rc;i++){
        for(j=0;j<rc;j++){
            if(i==j){
                ar[i][j]=0;
            }
            else{
                printf("Enter cost %d to %d ",i+1,j+1);
                scanf("%d",&ar[i][j]);
            }
        }
    }
    for(i=0;i<rc;i++){
        for(j=0;j<rc;j++){
            printf("%d\t",ar[i][j]);
        }
        printf("\n");
    }
    printf("Shortest Path\n");
    all_pair(ar,rc);
    for(i=0;i<rc;i++){
        for(j=0;j<rc;j++){
            printf("%d\t",ar[i][j]);
        }
        printf("\n");
    }
}