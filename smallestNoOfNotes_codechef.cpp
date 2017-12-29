#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,ctr=0;
		cin >> n;

		if(n>=100)
		{
			ctr=ctr+n/100;
			n=n%100;
		}

		if(n>=50)
		{
			ctr=ctr+n/50;
			n=n%50;
		}

		if(n>=10)
		{
			ctr=ctr+n/10;
			n=n%10;
		}

		if(n>=5)
		{
			ctr=ctr+n/5;
			n=n%5;
		}

		if(n>=2)
		{
			ctr=ctr+n/2;
			n=n%2;
		}

		if(n>=1)
		{
			ctr=ctr+n;
			n=n%1;
		}

		cout<<ctr<<endl;

	}
}
