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
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        if(min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}