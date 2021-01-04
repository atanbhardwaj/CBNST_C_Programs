# include <stdio.h>
# include <conio.h>
# include <math.h>
# include <process.h>
# include <string.h>

float fun(float x)
{
float temp;
temp=1/(1+(x*x));
return temp;
}

void main()
{
float result=1,a,b,h,sum;
int i,j,n;

printf("\n\n Enter the range - ");
printf("\n\n Lower Limit a - ");
scanf("%f" ,&a);
printf("\n\n Upper Limit b - ");
scanf("%f" ,&b);
printf("\n\n Enter number of subintervals - ");
scanf("%d" ,&n);

h=(b-a)/n;
sum=0;
sum=fun(a)+fun(b);
for(i=1;i<n;i++)
{
if(i%3==0)
{
sum+=2*fun(a+i*h);
}
else
{
sum+=3*fun(a+(i)*h);
}
}
result=sum*3*h/8;
printf("\n\n\n\n Value of the integral is %6.4f\t",result);
printf("\n\n\n Press Enter to Exit");
getch();
}

