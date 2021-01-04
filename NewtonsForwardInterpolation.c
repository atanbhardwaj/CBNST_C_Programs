#include<stdio.h>

int find_u(float a[10][10], int n, int x)
{
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if(a[i][j]>=x)
            return a[i-1][j];
    }
}

int fact(int x)
{
    int f=1;
    if(x == 0 || x == 1)
        return 1;
    while(x!=0)
    {
        f=f*x;
        x--;
    }
    return f;
}

float multi(float u, int var){
    int f= 1,hold = 1;
    float mu = u;
    f = fact(var);
    while(hold < var){
        mu = mu * (u-hold);
        hold++;
    }
    return mu/f;
}

void newton_forward(float a[10][10], int n, float u)
{
    int i,j;
    float sum=a[0][1] + u*a[0][2];
    for(i=2;i<=(n-1);i++){
            sum = sum + (multi(u,i)*a[0][i+1]);
    }
    printf("The value of function at given point is : %f",sum);
}

void main()
{
    int i,j,n,c,x;
    float a[10][10],u;
    printf("Enter the limit of x:\n");
    scanf("%d",&n);
    c=n;
    printf("Enter elements into the matrix:\n");
    for(j=0;j<2;j++)
    {
        for(i=0;i<n;i++)
            scanf("%f",&a[i][j]);
    }
    printf("Enter the value of x0\n");
    scanf("%d",&x);
    u=(x-find_u(a,n,x))/(a[1][0]-a[0][0]);
    printf("The value of u is: %5.3f\n",u);
    printf("\nThe Forward Difference table is:\n");
    for(j=2;j<=n;j++)
    {
        for(i=0;i<c;i++)
        {
            a[i][j]=a[i+1][j-1]-a[i][j-1];
        }
        c--;
    }
    c=n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=c;j++)
            printf("%5.3f\t",a[i][j]);
        c--;
        printf(" \n");
    }
    newton_forward(a,n,u);
}