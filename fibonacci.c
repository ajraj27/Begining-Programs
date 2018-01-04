#include<stdio.h>

int main()
{
	int n,a,b;
	scanf("%d",&n);
	
	a=0;
	b=1;

	for(int i=3;i<=n;i++)
	{
		int c=a+b;
		a=b;
		b=c;
	}

	if(n==1)
		printf("%d",a);
	else
		printf("%d",b);

}