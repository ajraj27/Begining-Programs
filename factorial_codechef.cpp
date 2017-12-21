#include<iostream>
using namespace std;

int main(){

	int t,n,ctr;
	cin>>t;

	while(t--)
	{
		ctr=0;
		cin>>n;

		for(int i =5;n/i>=1;i=i*5)
		{
			ctr=ctr+n/i;
		}
		cout << ctr;
	}
		return 0;

} 