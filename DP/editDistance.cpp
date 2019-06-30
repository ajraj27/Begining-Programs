#include<bits/stdc++.h>
using namespace std;

int minimum(int a,int b,int c){
	return min(min(a,b),c);
}

int getMin(string A,string B){
	int m=A.length();
	int n=B.length();

	if(m==0)
		return n;
	if(n==0)
		return m;

	int dp[m+1][n+1];

	for(int i=0;i<=n;i++)
		dp[0][i]=i;

	for(int i=0;i<=m;i++)
		dp[i][0]=i;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(A[i-1]==B[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+minimum(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	}

	return dp[m][n];
}

int main(){
	string a,b;
	cin >> a >> b;

	cout << getMin(a,b);
}