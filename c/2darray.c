#include<stdio.h>
int main(){
    int arr[10][10],x,y;

    printf("enter your size of array XxY:");
    scanf("%d%d",&x,&y);

     printf("Enter your array elements :\n");
    for(int i=0; i<x;i++){
        for(int j=0;j<y;j++){
            printf("Enter the element of arr[%d][%d]: ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
return 0;
}