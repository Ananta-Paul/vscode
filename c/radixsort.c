#include<stdio.h>
int max(int arr[],int n){
    int m=0;
    for(int i=0;i<n;i++){
        if(arr[i]>m)
        m=arr[i];
    }
    return m;
}
void countsort(int arr[],int exp,int n){
    int arr1[n];
    int count[10]={0},i;
    for(i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--){
        arr1[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++){
        arr[i]=arr1[i];
    }
}
void radixsort(int arr[],int n){
    int i, m=max(arr,n);
    for(i=1;m/i>0;i=i*10){
        countsort(arr,i,n);
    }
}
void print(int arr[],int n){
    printf("Sorted Array:");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
}
void main(){
    int arr[]={12,456,785,2,12,24,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixsort(arr,n);
    print(arr,n);
}