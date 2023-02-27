#include<Stdio.h>
#include<stdlib.h>
void merge(int ar[],int low,int up, int mid){
    int i=low;
    int j=mid+1;
    int k=low;
    int c[100];
    while(i<=mid && j<=up){
        if(ar[i]<ar[j]){
            c[k]=ar[i];
            i+=1;
            k+=1;
        }
        else if(ar[i]>=ar[j]){
            c[k]=ar[j];
            j+=1;
            k+=1;
        }
    }
    while(i<=mid){
        c[k]=ar[i];
        i+=1;
        k+=1;
    }
    while(j<=up){
        c[k]=ar[j];
        j+=1;
        k+=1;
    }
    for(i=low;i<=up;i++){
        ar[i]=c[i];
    }
}
void merge_sort(int ar[],int low,int up){
    int mid;
    if(low<up){
        mid=(low+up)/2;
        merge_sort(ar,low,mid);
        merge_sort(ar,mid+1,up);
        merge(ar,low,up,mid);
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
    merge_sort(ar,0,size-1);
    for(i=0;i<size;i++){
        printf("%d\t",ar[i]);
    }
}