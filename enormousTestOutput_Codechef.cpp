#include<iostream>
using namespace std;

int main()
{
	long int n,k,num;
	cin >> n >> k;
	int ctr=0;

	while(n--)
	{
		
		cin >> num;

		if(num%k==0)
			ctr++;
	}
	cout << ctr;

	return 0;



}