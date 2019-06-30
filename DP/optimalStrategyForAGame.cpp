#include<bits/stdc++.h>
using namespace std;



int getMaxPoints(vector<int> A){
	int n=A.size();
	if(n==0)
		return 0;

	int dp[n][n];

	for(int gap=0;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			int x=i+2<=j?dp[i+2][j]:0;
			int y=((i+1)<=(j-1))?dp[i+1][j-1]:0;
			int z=i<=j-2?dp[i][j-2]:0;

			dp[i][j]=max(A[i]+min(x,y),A[j]+min(y,z));
		}
	}

	return dp[0][n-1];
}

int main(){
	int n;
	cin >> n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin >> v[i];

	cout << getMaxPoints(v);
}