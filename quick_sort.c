#include<stdio.h>
#include<stdlib.h>
int partition(int ar[],int low,int up){
    int i=low;
    int j=up;
    int pivot=ar[low];
    int temp;
    while(i<j){
        while(ar[i]<=pivot){
            i+=1;
        }
        while(ar[j]>pivot){
            j-=1;
        }
        if(i<j){
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
        }
    }
    temp=ar[low];
    ar[low]=ar[j];
    ar[j]=temp;
    return j;
}
void quick_sort(int ar[],int low,int up){
    int pos;
    if(low<up){
        pos=partition(ar,low,up);
        quick_sort(ar,low,pos-1);
        quick_sort(ar,pos+1,up);
        
    }
}
void main(){
    int size,ar[100],i;
    printf("Enter size of the array");
    scanf("%d",&size);
    printf("Enter element");
    for(i=0;i<size;i++){
        scanf("%d",&ar[i]);
    }
    for(i=0;i<size;i++){
        printf("%d\t",ar[i]);
    }
    printf("\n");
    printf("Sorted array is\n");
    quick_sort(ar,0,size-1);
    for(i=0;i<size;i++){
        printf("%d\t",ar[i]);
    }
}