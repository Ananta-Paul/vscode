#include<stdio.h>
void merge(int arr[],int si,int mid,int ei){
    int i=si,j=mid+1,temp[ei-si+1],k=0;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        temp[k++]=arr[j++];
    }
    while(i<=mid)
    temp[k++]=arr[i++];
    while(j<=ei)
    temp[k++]=arr[j++];
    for(int a=0,b=si;b<=ei;a++,b++){
        arr[b]=temp[a];
    }
}
void devide(int arr[],int si,int ei){
    if(si<ei){
   int mid=si+(ei-si)/2;
   devide(arr,si,mid);
   devide(arr,mid+1,ei);
   merge(arr,si,mid,ei);
}
}
void main(){
    int i,n;
    // printf("Enter the number of element: ");
    // scanf("%d",&n);
    n=21;
    int arr[]={34, 88, 89, 39, 67, 71, 85, 57, 18, 7, 61, 50, 38, 6, 60, 18, 19, 46, 84, 74, 59};
    // for ( i = 0; i < n; i++){
    //     printf("Enter %d element: ",i+1);
    //     scanf("%d",&arr[i]);
    // }
    devide(arr,0,n-1);
        printf("Sorted array by merge sort:");
    for( i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
                    