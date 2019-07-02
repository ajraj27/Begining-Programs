#include<bits/stdc++.h>
using namespace std;

int maxAreaHistogram(int hist[],int n){
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

int getMaxArea(vector<vector<int> >A){
	int m=A.size();
	int n=A[0].size();

	int temp[n]={0};
	int maximum=INT_MIN;

	for(int row=0;row<m;row++){
		for(int col=0;col<n;col++){
			if(A[row][col]==1)
				temp[col]++;
			else
				temp[col]=0;
		}

		maximum=max(maximum,maxAreaHistogram(temp,n));
	}

	return maximum;
}

int main(){
	int m,n;
	cin >> m >> n;

	vector<vector<int> > v(m,vector<int>(n));

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> v[i][j];

	cout << getMaxArea(v);	
}