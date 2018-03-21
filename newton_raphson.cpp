#include<iostream>
#include<math.h>
#define fcn(x) cos(x)-x // update the function here if not a polynomial
#define fcnd(x) -sin(x)-1 // update the function here if not a polynomial
#include<stdlib.h>
int main()
{
	
	int n,i,itr=0,check=1;
	float *p;

	char pf,df;
	printf("Is function a polynomial function?(y/n):");
	scanf("%c",&pf);
	
	if (pf=='y')
	{
	printf("Enter degree of the polynomial function:");
	scanf("%d",&n);
	p = (float*) calloc(n, sizeof(float));
	
	printf("Enter the %d coefficients of x^0 to x^%d:",n+1,n);
	for (i=0;i<=n;i++)
    scanf("%f",p+i);
	// storing the coefficients such that index-i represesnts the power and data in adress p+i represents coefficients
    }else{	
    printf("Okay,have you defined it in the code?(y/n):");
	scanf(" %c",&df);
    if (df=='n')
    {printf("Pls define the function and its derivative at lines 3 and 4 of the code, respectively. After that, pls re-run this software");return 0;}
	}
	    
    float f,fd,xn,x=1,err;
    
    
    do
    {
    	
    itr=itr+1;
    if (pf=='y')
    {	
	f=0;
	for (i=0;i<=n;i++)
	f=f+*(p+i)*pow(x,i);
	}else
    {
    f=fcn(x);	
	}
	if (f==0)
	break;
	// 'f' now contains f(x) value
	
	
	if (pf=='y')
    {
	fd=0;
	for (i=1;i<=n;i++)
	fd=fd+i*(*(p+i))*pow(x,i-1);
	}else
    {
    fd=fcnd(x);	
	}
	// 'fd' now contains f'(x) value
	
	
	if (fd==0)
	fd=0.000001;
	// to avoid f'(x) being 0; otherwise, next x will become infinity
	
	xn=x-f/fd;// newton-raphson equation
	
	
	err=xn-x;
	if (err<=0)
	err=-err;
	// calculate error between new x (xn) and  old x 
	if (itr>9999&&err>10)
	{check=0;
	break;}
	// checking if there is some solution or not even after 10k iterations
	
	
	x=xn;
	}while(err>0.000001);// checking if tolerance level is reached
	if (check==1)
    {printf("The root of this function is %f. It is achieved in %d iterations",x,itr);
}else
{
	printf("Not possible to get the root with the given set of inputs");}
	
    return 0;
}
