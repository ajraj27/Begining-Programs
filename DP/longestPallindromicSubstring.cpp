#include<bits/stdc++.h>
using namespace std;

int longestPallindromicSubstring(string A){
	int n=A.length();
	if(n==0)
		return 0;

	int dp[n][n];
	int res=1;
	int start=0,end=n-1;

	for(int i=0;i<n;i++)
		dp[i][i]=1;

	for(int gap=1;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
			dp[i][j]= A[i]==A[j] && ((i+1)<=(j-1)?dp[i+1][j-1]:1);

			if(A[i]==A[j] && dp[i+1][j-1]){
				if(gap+1>res){
					res=gap+1;
					start=i;
					end=j;
				}

			}
		}
	}

	return A.substr(start,end-start+1);
}

int main(){
	string A;
	cin >> A;

	cout << longestPallindromicSubstring(A);
}