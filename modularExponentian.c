#include<stdio.h>

int mod(int base,int power,int m)
{
	if(power==0)
		return 1;

	else if(power%2==0){
		int y=mod(base,power/2,m);
		return (y*y)%m;
	}

	else
		return ((base%m)*(mod(base,power-1,m)))%m;


}

int main()
{
	int base,power,m;

	printf("Enter base , exponent , divisor :");
	scanf("%d%d%d ",&base,&power,&m);

	int ans=mod(base,power,m);

	printf("\nAnswer:%d",ans);

	return 0;
}