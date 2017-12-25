#include<iostream>
using namespace std;

int main()
{
	int t,a,b,min;
	cin >> t;

	while(t--)
	{
		cin >> a >> b;

		cout<< (a>b?a:b) <<" "<<a+b<<endl;

	}
}