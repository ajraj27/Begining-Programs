#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[],int n){
	stack<int> s;
	int i=0,max=-1,area,curr;

	while(i<n){
		if(s.empty() || hist[s.top()]<=hist[i]){
			s.push(i);
			i++;
		}else{
			curr=s.top();
			s.pop();
			if(s.empty())
				area=hist[curr]*i;
			else
				area=hist[curr]*(i-s.top()-1);

			if(area>max)
				max=area;
		}
	}

	while(!s.empty()){
		curr=s.top();
		s.pop();

		if(s.empty())
			area=hist[curr]*i;
		else
			area=hist[curr]*(i-s.top()-1);

		if(area>max)
			max=area;
	}

	return max;

}

int main(){
	int n;
	cin >> n;

	int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	cout << getMaxArea(a,n);

}