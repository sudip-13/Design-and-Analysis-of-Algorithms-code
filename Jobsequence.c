#include<stdio.h>
#include<stdlib.h>
struct list{
    char name[10];
    int profit;
    int deadline;
};
int min_value(int x,int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}
void Job_sequence(int size,struct list *ar){
    int i,j,dmax=0,slot[100],filledslot=0,dmin=0,total_profit=0;
    struct list temp;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(ar[j].profit<ar[j+1].profit){
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    for(i=0;i<size;i++){
        if(ar[i].deadline>dmax){
            dmax=ar[i].deadline;
        }
    }
    for(i=1;i<=dmax;i++){
        slot[i]=-1;
    }
    for(i=0;i<size;i++){
        dmin=min_value(dmax,ar[i].deadline);
        while (dmin>=1)
        {
            if(slot[dmin]==-1){
                slot[dmin]=i;
                filledslot++;
                break;
            }
            dmin--;
        }
        if(filledslot==dmax){
            break;
        }
    }
    printf("Best order of job is to\n");
    for(i=1;i<=dmax;i++){
        printf("%s\t",ar[slot[i]].name);
    }
    printf("\n");
    for(i=1;i<=dmax;i++){
        total_profit+=ar[slot[i]].profit;
    }
    printf("Total profit = %d",total_profit);
}
void main(){
    int size,i;
    struct list ar[100];
    printf("Enter size of the structure ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter:-\n");
        printf("\tjob name: ");
        scanf("%s",&ar[i].name);
        printf("\tdeadline: ");
        scanf("%d",&ar[i].deadline);
        printf("\tprofit: ");
        scanf("%d",&ar[i].profit);
    }
    Job_sequence(size,ar);
}