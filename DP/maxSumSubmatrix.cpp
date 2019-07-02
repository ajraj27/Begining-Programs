#include<bits/stdc++.h>
using namespace std;

int kadane(int a[],int n){
	int maxsofar=0,totalmax=0;

	for(int i=0;i<n;i++){
		maxsofar+=a[i];

		if(maxsofar<0)
			maxsofar=0;

		else if(totalmax<maxsofar)
			totalmax=maxsofar;
	}
	
	return totalmax;
}

int getMaxSum(vector<vector<int> > A){
	int m=A.size();
	int n=A[0].size();
	int temp[m];
	int maxSum=INT_MIN;

	for(int left=0;left<n;left++){
		for(int i=0;i<m;i++)
			temp[i]=0;

		for(int right=left;right<n;right++){
			for(int i=0;i<m;i++)
				temp[i]+=A[i][right];

			int currSum=kadane(temp,m);
			maxSum=max(maxSum,currSum);
		}
	}

	return maxSum;
}

int main(){
	int m,n;
	cin >> m >> n;

	vector<vector<int> > v(m,vector<int>(n));

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> v[i][j];

	cout << getMaxSum(v);	
}