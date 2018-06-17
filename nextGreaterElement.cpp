#include<bits/stdc++.h>
using namespace std;

void nextGreaterElement(int a[],int n)
{
	stack<int> s;
	s.push(a[0]);

	for(int i=1;i<n;i++)
	{
		int next=a[i];

		if(!s.empty())
		{
			int element=s.top();
			s.pop();

			while(next > element)
			{
				cout << element << "--->" << next << endl;
				if(s.empty())
					break;
				element=s.top();
				s.pop();

			}

			if(next < element)
				s.push(element);
		}

		s.push(next);
	}

	while(!s.empty())
	{
		cout << s.top() << " ---> "<<-1<<endl;
		s.pop();
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	nextGreaterElement(a,n);
}