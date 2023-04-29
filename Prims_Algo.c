#include <stdio.h>
#include <stdlib.h>
int a,b,u,v,ne=1;
int visited[10]={0},min,min_cost=0;
void prims(int g[][100],int n){
    
    while (ne<n)
    {
        min=999;
            for(int i=0;i<n;i++)
		    for(int j=0;j<n;j++)
		        if(g[i][j]< min)
                    if(visited[i]!=0)
                    {
                        min=g[i][j];
                        a=u=i;
                        b=v=j;
                    }
                if(visited[u]==0 || visited[v]==0)
                {
                    printf("(%d-%d), ",a+1,b+1);
                    ne++;
                    min_cost+=min;
                    visited[b]=1;
                }
                g[a][b]=g[b][a]=999;
            }
	printf("\n Minimun cost=%d",min_cost);
}
void main(){
    int rc,matrix[100][100];
    printf("Enter no of row & column");
    scanf("%d",&rc);
    printf("Enter cost matrix\n");
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("ar[%d][%d]=",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Your Entered cost matrix is\n");
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
 
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            if(matrix[i][j]==0){
                matrix[i][j]=999;
            }
        }
    }
    visited[1]=1;
    printf("\n Minimum spanning tree has edges \n");
    prims(matrix,rc);
}