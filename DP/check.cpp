#include<bits/stdc++.h>
using namespace std;

int pallindromePartitioning(string A){
	int n=A.length();
	if(n==0)
		return 0;

	int dp[n][n];
	int pal[n][n];

	for(int i=0;i<n;i++){
		dp[i][i]=1;
		pal[i][i]=1;
	}

	for(int gap=1;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			pal[i][j]=A[i]==A[j] && (i+1)<=(j-1)?pal[i+1][j-1]:1;

			if(pal[i][j])
				dp[i][j]=0;

			else{
				dp[i][j]=INT_MAX;
				for(int k=i;k<j;k++)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
			}
		}
	}

	return dp[0][n-1];
}

int main(){
	string A;
	cin >> A;

	cout << pallindromePartitioning(A);
}