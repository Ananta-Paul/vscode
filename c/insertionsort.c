#include<stdio.h>

int main(){
    int n,a,b;
    printf("Enter the size of array you want to make:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter thee values: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}