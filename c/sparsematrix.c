#include<stdio.h>
int main(){
int arr[10][10],x,y,i,j,k=1;
for(i=0;i<6;i++){
    for(j=0;j<6;j++){
        if(j<=i){
            arr[i][j]=k;
            k++;
        }
        else
        arr[i][j]=0;
    }
}
for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
return 0;

}


