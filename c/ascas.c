#include<stdio.h>
void main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
        printf("%d",i);
        if(i!=j)
        printf("*");
        }
         printf("\n");
    }
    for(int k=n;k>=1;k--){
        for(int l=k;l>=1;l--){
        printf("%d",k);
        if(l!=1)
        printf("*");
        }
        printf("\n");
    }
   
}