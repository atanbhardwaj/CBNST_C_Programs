#include<stdio.h>
#include<math.h>

void enterval(float a[][100],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(n+1);j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
}

void printmat(float a[][100], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(n+1);j++)
        {
            printf("%5.2f ",a[i][j]);
        }
        printf("\n");
    }
}
void divfac(float a[][100],int n,int i,float fac)
{
    int k;
    for(k=0;k<(n+1);k++)
        {a[i][k]=a[i][k]/fac;}
}

void swapping(float a[][100], int n, int i, int j)
{
    float temp;
    int k=0;
    while(k<(n+1))
    {
        temp=a[i][k];
        a[i][k]=a[j][k];
        a[j][k]=temp;
        k++;
    }
}

void check(float a[][100], int n)
{
    int i=0,j=0;
    while(i<n)
    {
        if(a[i][j]==1)
            break;
        i++;
    }
    if(i>=n)
        i=0;
    swapping(a,n,i,j);
    if(a[0][0]!=1&&a[0][0]!=0)
        divfac(a,n,0,a[0][0]);
}

void uppertri(float a[][100], int n)
{
    int i,j,k,index=0;
    float commonfac,factor;
    for(j=0;j<(n+1);j++)
    {
        for(i=0;i<n;i++)
        {
            if(a[i][j]==0&&i==j)
                {swapping(a,n,i,(i+1));divfac(a,n,i,a[i][j]);}
            if(i>j)
            {
                factor=a[i][j];
                for(k=0;k<(n+1);k++)
                    {a[i][k]-=(factor*a[index][k]);}
                commonfac=a[i][j+1];
                if(commonfac!=0)
                    divfac(a,n,i,commonfac);
            }
        }
        index++;
    }
    if(a[n-2][n-2]==0)
        swapping(a,n,i-1,i-2);
}
void roots(float a[][100],int n)
{
    float arr[100],multi,sum;
    int i=(n-2),k,t=1;
    arr[n-1]=(a[n-1][n]/(a[n-1][n-1]));
        while(t!=n)
        {
            for(k=0;k<t;k++)
            {
                multi=a[i][i+k+1]*arr[i+k+1];
                sum+=multi;
            }
            if((a[n-t-1][n-t-1])!=0)
                arr[n-t-1]=(a[i][n]-sum)/(a[n-t-1][n-t-1]);
            sum=0;
            i--;
            t++;
        }
    for(i=0;i<n;i++)
        printf("\nValue of x%d is %f",i+1,(arr[i]));
}
int main()
{
    int n;
    float a[100][100];
    printf("Enter the number of unknowns \n");
    scanf("%d",&n);
    printf("Enter the values \n");
    enterval(a,n);
    printf("The Augumented Matrix is: \n");
    printmat(a,n);
    check(a,n);
    printf("The upper triangular is: \n");
    uppertri(a,n);
    printmat(a,n);
    roots(a,n);
    return 0;
}