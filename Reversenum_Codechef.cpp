#include<iostream>
using namespace std;

int main()
{
	int t,n,i,sum,rem;
	cin >> t;

	while(t--)
	{
		cin >> n;
		sum=0;

		while(n>0)
		{
			rem=n%10;
			sum=sum*10+rem;
			n=n/10;
		}

		cout  << sum << endl;
	}
}