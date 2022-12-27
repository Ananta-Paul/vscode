#include<stdio.h>
#include<math.h>
int main()
{
float x[15], y[15], sum, X, prod;
int i, j, k, n;
printf("Enter the no. of points:\t");
scanf("%d",&n);
printf("Enter the values of x at which y is required : \t");
scanf("%f",&X);
printf("Enter the values of x and y:\t");
for(i=1;i<=n;i++)
{
scanf("%f%f",&x[i],&y[i]);
}
sum = 0;
for(i=1;i<=n;i++)
{
prod = 1;
for(j=1;j<=n;j++)
{
if(j!=i)
{
prod = prod * (X-x[j])/(x[i]-x[j]);
}
}
sum = sum + (prod*y[i]);
}
printf("\nAt x = %f, \n y = %f", X, sum);
return(0);
}