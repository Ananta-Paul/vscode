#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    int lowest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]<arr [lowest])
    lowest=left;
    if(right<n && arr[right]<arr [lowest])
 lowest=right;
    if (lowest!=i){
        swap(&arr[i],&arr [lowest]);
        heapify(arr,n ,lowest);
    }
}
void print(int arr[],int n){
    printf("Array:");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;--i){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void main(){
    int i,j;
    int arr[]={1,12,9,5,6,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    print(arr,n);
}