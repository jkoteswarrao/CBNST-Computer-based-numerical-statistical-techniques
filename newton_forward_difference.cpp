#include<iostream>
#include<math.h>
int main()
{
	int itr,n,i,j;
	printf("enter number of observations:");
    scanf("%d",&n);
    float a[n][n+1],fx=0,df,nf,x,p;
    printf("enter input values:");
    for (i=0;i<n;i++)
    {
    	scanf("%f",&a[i][0]);
	}
	printf("enter corresponding output values:");
    for (i=0;i<n;i++)
    {
    	scanf("%f",&a[i][1]);
	}
    // first two columns of the newton forward difference table is filled
    
    for (j=2;j<=n;j++)
    {
	    for (i=0;i<=n-j;i++)
		{
		a[i][j]=a[i+1][j-1]-a[i][j-1];
		}
		for (i=n-j+1;i<n;i++)
		{
		a[i][j]=0;
		}
	}
    // from 3rd to last columns are filled
    
    
    printf("Newton Forward Difference Matrix:\n");
    for (i=0;i<n;i++)
	{
		printf("\n");
		for (j=0;j<=n;j++)
		{
			printf("\t%f",a[i][j]);
		}				
	}
	
	printf("Enter the value x for which you want f(x):");
	
	scanf("%f",&x);
	
	p=(x-a[0][0])/(a[1][0]-a[0][0]);
	
	
	
	for (j=1;j<=n;j++)
	{
		nf=1;//numerator for 1st term
		df=1;//denominator for 1st term
		for(i=1;i<j;i++)
		{
		nf=nf*(p-i+1); 
		df=df*i;
	    }// for calculation of numerators and denominators of j-th term
	    fx=fx+a[0][j]*nf/df;// accumulating the values of different terms
	}
	
	
	printf("\nf(%f)=%f",x,fx);
	
    return 0;
}
