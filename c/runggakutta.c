#include<stdio.h> 

#include<math.h> 
/*function*/ 
float f(float x, float y) 
{ 
float a; 
a = x*x + y*y; 
return(a); 
} 
/*Main Program*/ 
int main( ) 
{ 
 float x0, y0, xn, y1, h, k1, k2, k3, k4, k; 
 
printf("\n Enter starting val of x & y i.e., xo, yo: "); 
scanf("%f%f", &x0, &y0); 
printf("\nEnter the val of x at which y is required "); 
scanf("%f",&xn); 
printf("\nEnter the step size "); 
scanf("%f", &h); 
do 
{ 
 k1 = h*f(x0,y0); 
 k2 = h*f(x0+h/2, y0 + k1/2); 
 k3 = h*f(x0+h/2,y0+k2/2); 
 k4 = h*f(x0 + h, y0+k3); 
 k= (k1+ 2*k2 + 2*k3 + k4)/6.0; 
 y1 = y0 + k; 
 printf("\n The value of y = %6.4f at x = %6.2f", y0,x0); 
 y0 = y1; 
 x0 = x0 +h; uuiiii
}while(x0<=xn);
return 0;
}