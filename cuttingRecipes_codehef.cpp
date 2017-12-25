#include<iostream>
using namespace std;

int GCD(int a,int b)
{
	if(a>b)
	{
		if(b==0)
			return a;
		else
			return GCD(b,a%b);
	}

	else
		if(a==0)
			return b;
		else
			return GCD(a,b%a);
}

int main()
{
	int t,i;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		int a[n];

		for(i=0;i<n;i++)
			cin >> a[i];

		int res=a[0];
		for(i=1;i<n;i++)
			res=GCD(res,a[i]);

		for(i=0;i<n;i++)
			cout <<a[i]/res<<" ";

		cout<< endl;

	}


}