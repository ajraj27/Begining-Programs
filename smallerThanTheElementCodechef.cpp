#include<bits/stdc++.h>
#include<iterator>
using namespace std;

int main()
{
	long long int n,i;
	cin >> n;

	set<long long int>s;
	set<long long int>:: iterator it;

	for(i=0;i<n;i++)
	{
		long long int num;
		cin >> num;

		s.insert(num);

		if(*(s.begin())==num)
			cout << -1 <<endl;

		else
		{
			it=s.find(num);
			cout<< *(prev(it,1)) << endl;
		}
		
	}
}