#include<stdio.h>
#define F(x,y) (x+y)
void main()
{
int i,n;
float x0,y0,h,xn,k1,k2,k3,k4,x,y,k;
printf("\n Enter the values: x0,y0,h,xn:\n");
scanf("%f%f%f%f", &x0,&y0,&h,&xn);
n=(xn-x0)/h;
x=x0;
y=y0;
for(i=0;i<=(n+1);i++)
{
k1=h*F(x,y);
k2=h*F(x+h/2.0,y+k1/2.0);
k3=h*F(x+h/2.0,y+k2/2.0);
k4=h*F(x+h,y+k3);
k=(k1+(k2+k3)*2.0+k4)/6.0;
printf("\n X=%f Y=%f", x, y);
x=x+h;
y=y+k;
}
}