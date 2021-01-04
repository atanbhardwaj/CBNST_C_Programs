
# include <stdio.h>
# include <conio.h>
# include <math.h>
# include <process.h>
# include <string.h>

void main()
{

int n,i,j;
float ax[100],ay[100],x=0,y=0,nr,dr;
printf("\n Enter the number of terms - ");
scanf("%d",&n);
printf("\n\n Enter the value in the form of x - ");
for (i=0;i<n;i++)
{
printf ("\n\n Enter the value of x%d - ", i+1);
scanf("%f",&ax[i]);
}
printf("\n\n Enter the value in the form of y - ");
for (i=0;i<n;i++)
{
printf("\n\n Enter the value of y%d - ", i+1);
scanf ("%f",&ay[i]);
}
printf("\n Enter the value of x for ");
printf("\n which you want the value of y - ");
scanf("%f",&x);
for(i=0;i<n;i++)
{
nr=1;
dr=1;
for(j=0;j<n;j++)
{
if(j!=i)
{
nr=nr*(x-ax[j]);
dr=dr*(ax[i]-ax[j]);
}
y+=(nr/dr)*ay[i];
}
}
printf("\n\n When x=%5.2f,y=%5.2f ",x,y);
printf("\n\n\n Press Enter to Exit");
getch();
}