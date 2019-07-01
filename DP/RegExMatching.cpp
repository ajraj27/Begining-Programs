#include<bits/stdc++.h>
using namespace std;

int regexMatching(string A,string B){
	int m=A.length();
	int n=B.length();

	int dp[m+1][n+1];

	dp[0][0]=1;

	for(int i=1;i<=m;i++)
		dp[i][0]=0;

	for(int i=1;i<=n;i++){
		if(B[i-1]=='*')
        	dp[0][i]=dp[0][i-2];
        else
        	dp[0][i]=0;
    }

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(A[i-1]==B[j-1] || B[j-1]=='.')
				dp[i][j]=dp[i-1][j-1];

			else if(B[j-1]=='*'){
				dp[i][j]=dp[i][j-2];

				if(A[i-1]==B[j-2] || B[j-2]=='.')
					dp[i][j]|=dp[i-1][j];
			}

			else
				dp[i][j]=0;
		}
	}


	// for(int i=0;i<=n;i++)
	// 	cout << dp[0][i] << " ";

	return dp[m][n];
}

int main(){
	string s,t;
	cin >> s >> t;

	cout << regexMatching(s,t);
}