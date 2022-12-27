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
    int c=1;
    while(c<n){
        for(int i=0;i<n-c;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        c++;
    }

    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}