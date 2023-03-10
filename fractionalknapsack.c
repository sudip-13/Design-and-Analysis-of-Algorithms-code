#include<stdio.h>
#include<stdlib.h>
struct list{
    char name[10];
    int wieght;
    int profit;
    float ratio;
};
void Frac_knapsack(int knapsack,int size,struct list *ar){
    int i,j;
    struct list temp;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(ar[j].ratio<ar[j+1].ratio){
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    float total_profit=0;
    for(i=0;i<size;i++){
        if(knapsack==0){
            break;
        }
        if(ar[i].wieght<=knapsack){
            total_profit+=ar[i].profit;
            knapsack-=ar[i].wieght;
        }
        else{
            total_profit+=(float)ar[i].profit*(float)knapsack/(float)ar[i].wieght;
            break;
        }
    }
   printf("Total profit is %f",total_profit);
}
void main(){
    int size,knapsack,i;
    struct list ar[10];
    printf("Enter no of items");
    scanf("%d",&size);
    printf("Enter capacity of knapsack");
    scanf("%d",&knapsack);
    for(i=0;i<size;i++){
        printf("Enter items ");
        scanf("%s",&ar[i].name);
        printf("Enter profit");
        scanf("%d",&ar[i].profit);
        printf("Enter weight ");
        scanf("%d",&ar[i].wieght);
        ar[i].ratio=(float)ar[i].profit/(float)ar[i].wieght;
    }
    Frac_knapsack(knapsack,size,ar);
}