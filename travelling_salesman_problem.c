#include<stdio.h>
#include<stdlib.h>
int visit[10],cost=0;
int find_path(int g[][100],int rc,int c){
    int nc=999,kmin,min=999;
    for(int i=0;i<rc;i++){
        if(g[c][i]!=0 && visit[i]==0){
            if(g[c][i]<min){
                min=g[i][0]+g[c][i];
                kmin=g[c][i];
                nc=i;
            }
        }
    }
    if(min!=999){
        cost+=kmin;
    }
    return nc;
}
void t_s_p(int g[][100],int rc,int j){
    visit[j]=1;
    printf("%d->",j+1);
    int visited=find_path(g,rc,j);
    if(visited==999){
        visited=0;
        printf("%d",visited+1);
        cost+=g[j][visited];
        return ;
    }
    t_s_p(g,rc,visited);
}
void main(){
    int rc,tsp[100][100];
    printf("Enter no of row and column");
    scanf("%d",&rc);
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("Enter cost of %d to %d ",i+1,j+1);
            scanf("%d",&tsp[i][j]);
        }
        visit[i]=0;
    }
    for(int i=0;i<rc;i++){
        for(int j=0;j<rc;j++){
            printf("%d\t",tsp[i][j]);
        }
        printf("\n");
    }
    printf("path\t");
    t_s_p(tsp,rc,0);
    printf("\nMinimum cost\n");
    printf("%d\n",cost);   
}