#include<stdio.h>

int main(){
int i,j,a,b,arr[5],t;
printf("Enter the numbers of your array :");
for(i=0;i<5;i++)
scanf("%d",&arr[i]);
printf("\n Your array=");
for(i=0;i<5;i++)
printf("%d ,",arr[i]);
for(i=0;i<5;i++){
for(j=i+1;j<5;j++)
{
   if (arr[j]>arr[i]){
   t=arr[i];
   arr[i]=arr[j];
   arr[j]=t;
}}}

printf("\nThe two largest numbers are:%d,%d ",arr[0],arr[1]);
return 0;
}