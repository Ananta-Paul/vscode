#include<stdio.h>
#include<math.h>
void main(void)
{
int i, n, j, k, l;
float xn, y[20], f[10][10], X[10], Y[10], h, u, p;
printf("Enter the value of n (No. of pairs - 1):\n");
scanf("%d",&n);
printf("Enter the last value of x\n");
scanf("%f",&xn);
printf("Enter the step size h: ");
scanf("%f",&h);
printf("Enter the values of y\n");
for(i=0;i<n+1;i++)
scanf("%f",&y[i]);
printf("Enter the required no. of interpolated values of y:\n");
scanf("%d",&l);
printf("Enter the %d values of X for which values of y are required :\n",l);
for(k=0;k<l;k++)
scanf("%f",&X[k]);
for(j=0;j<n+1;j++)
f[0][j] = y[j];
for(i=1;i<n+1;i++)
for(j=i;j<n+1;j++)
f[i][j] = f[i-1][j] - f[i-1][j-1];
for(k=0;k<l;k++)
{
u = (X[k] - xn)/h;
Y[k] = y[n];
p = 1;
for(i = 1;i<n+1;i++){    
    p=p*(u+i-1)/i;
Y[k] = Y[k] + p * f[i][n];
}
printf("The values of X and Y are : %f\t%f\n",X[k],Y[k]);
}
}