#include<iostream>
#include<math.h>

int main()
{
	int i,j,n,p,k,got_p;
	printf("Enter number of equations:");
	scanf("%d",&n);
	float a[n][n+1],tp,b[n];
	
	
	
	
	for (i=0;i<n;i++)
	{
	
		printf("\n Enter coefficients of equation %d:",i+1);
		for (j=0;j<=n;j++)
		{
			scanf("%f",&a[i][j]);
		}
		
	}
	// 'a' is augmented matrix now;
	
			
	for (i=0;i<n-1;i++)
	{
		got_p=0;
		for (p=i;p<n;p++)
		{
			if (a[p][i]!=0)
            {got_p=1;
			break;}
		}
		if (got_p==0)
		break; // by breaking we avoid further iterations as we know already it's not possible to solve such a set of equations 
		// finding 'p' to swap if required and to test the possibility of solving the set of equations           
            
            
		  if (p!=i)
		  {
		  	for (j=0;j<=n;j++)
		  	{
		  		tp=a[p][j];
		  		a[p][j]=a[i][j];
		  		a[i][j]=tp;		  		
			}
		  }
		  // swapped row-i with row-p if p!=i
			
			
		for (k=i+1;k<n;k++)
		{
			tp=a[k][i]/a[i][i];
			for (j=0;j<=n;j++)
		  		{
		  		
		  			a[k][j]=a[k][j]-tp*a[i][j];
				}
		}
		// for making all the elements of lower triangular matrix=0
			
    }
    
    if (got_p==1&&a[n-1][n-1]!=0)// 
    {
    	
	printf("Gauss Elimination Matrix:\n");
    for (i=0;i<n;i++)
	{
		printf("\n");
		for (j=0;j<=n;j++)
		{
			printf("\t%f",a[i][j]);
		}				
	}
	for (i=n-1;i>=0;i--)
	{
		
		tp=0;
		for (j=i+1;j<n;j++)
		{
			tp=tp+b[j]*a[i][j];
		}
		
		b[i]=(a[i][n]-tp)/a[i][i];
					
	}
	// for putting solution value in 'b'
	
		for (i=0;i<n;i++)
	{
			printf("\nSolution for x%d: %f",i+1,b[i]);				
	}
    }else
    {
    	printf("A single solution is not possible for the given set of equations");
	}
    return 0;
}

