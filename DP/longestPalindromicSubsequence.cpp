#include<bits/stdc++.h>
using namespace std;

int getMaxLength(string A){
	int n=A.length();

	if(n==0)
		return 0;

	int dp[n][n];

	for(int i=0;i<n;i++)
		dp[i][i]=1;

	for(int gap=1;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			int x=(i+1)<=(j-1)?dp[i+1][j-1]:0;
			int y=i+1<=j?dp[i+1][j]:0;
			int z=i<=j-1?dp[i][j-1]:0;

			if(A[i]==A[j])
				dp[i][j]=x+2;
			else
				dp[i][j]=max(y,z);

		}
	}

	return dp[0][n-1];
}

int main(){
	string s;
	cin >> s;

	cout << getMaxLength(s);
}