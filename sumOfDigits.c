#include<stdio.h>

int main()
{
	long int t,res,n;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		int sum=0;

		while(n>0)
		{
			res=n%10;
			sum=sum+res;
			n=n/10;

		}
		printf("%d\n",sum);
	}
	return 0;	
}