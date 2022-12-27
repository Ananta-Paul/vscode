#include<stdio.h>
#include<stdlib.h>
long long int fib(int n,long long int a[]){
    if(a[n]!=0) return a[n];
    if (n==1)return 0;
    if(n==2||n==3)return 1;
    a[n]=fib(n-1,a)+fib(n-2,a);
    return a[n];
}
int main(){
    printf("Enter the position:");
    int n;
    long long int a[200]={0};
    scanf("%d",&n);
    printf ("%d",fib(n,a));
    return 0;
}