#include<stdio.h>
#define F(x,y) (x–y)/(x+y)
void main ( )
{
int i,n;
float x0,y0,h,xn,x,y;
printf("\n Enter the values: x0,y0,h,xn: \n");
scanf ("%f%f%f%f",&x0,&y0,&h,&xn);
n=(xn - x0)/h+1;
for (i=1;i<=n;i++)
{
y=y0+h*((x0-y0)/(x0+y0));
x=x0+h;
printf("\n X=%f Y=%f",x0,y0);
if(x<xn)
{
x0=x;
y0=y;
}
}
}