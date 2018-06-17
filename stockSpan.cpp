#include<bits/stdc++.h>
using namespace std;

void calculateStockSpan(int price[],int n)
{
	stack<int>s;
	int span[n];
	s.push(0);
	span[0]=1;

	for(int i=1;i<n;i++)
	{
		while(!s.empty() && price[s.top()]<=price[i])
			s.pop();

		span[i]=(s.empty())?(i+1):(i-s.top());

		s.push(i);
	}

	for(int i=0;i<n;i++)
		cout << span[i] << " ";
}

int main()
{
	int n;
	cin >> n;
	int price[n];

	for(int i=0;i<n;i++)
		cin >> price[i];

	calculateStockSpan(price,n);
}