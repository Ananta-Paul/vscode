#include<stdio.h>
void main(void)
{
int i, n, j, k, l;
float x0, y[20], f[10][10], X[10], Y[10], h, u, p;
printf("\nEnter the value of n(No. of data pairs - 1) : \n");
scanf("%d",&n);
printf("\nEnter the initial values of x :\n");
scanf("%f", &x0);
printf("\nEnter the step size\n ");
scanf("%f", &h);
printf("Enter the values of y\n ");
for(i=0;i<n+1;i++)
scanf("%f",&y[i]);
printf("Enter the required no. of interpolated values of y :\n");
scanf("%d",&l);
printf("Enter the %d values of X for which values of y are required :\n",l);
for(k=0;k<l;k++)
scanf("%f",&X[k]);
for(j=0;j<n+1;j++)
f[0][j]=y[j];
for(i=1;i<n+1;i++)
for(j=0;j<n+1-i;j++)
f[i][j] = f[i-1][j+1] - f[i-1][j];
for(k=0;k<l;k++)
{
u=(X[k] -x0)/h;
Y[k] = y[0];
p=1;
for(i=1;i<n+1;i++)
{
p=p*(u-i+1)/i;
Y[k] = Y[k] + p * f[i][0];
}
printf("The value of x and y are:%f\t%f\n",X[k],Y[k]);
}
}
