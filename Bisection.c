#include<stdio.h>
#include<math.h>
#define EPSILON 0.01

float func(float a)
{
    //return a*a*a-a*a+2;
    //return (a*log(a))-1.2;
    //return a*cos(a);
   //return 3*a+sin(a)-exp(a);
   //return exp(a)-3*log(a);
   return a*a*a-0.165*a*a+0.0003993;
}
void bis(float a,float b)
{
     float c=a;
    if(func(a)*func(b)>=0)
    {
        printf("Incorrect a and b"); return;}
   
    while((b-a)>=EPSILON)
    {
        c=(a+b)/2;
        if(func(c)==0.0)
            break;
        else if(func(c)*func(a)<0)
            b=c;
        else
            a=c;
        
    }
    printf("Root is :%f",c);
}

int main()
{
    //bis(-5,3);
    //bis(-1,1);
    bis(0,0.11);
    return 0;
}