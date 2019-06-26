#include<bits/stdc++.h>
using namespace std;

int getNumOfCoins(int a[],int n,int m){
	int dp[n+1];
	dp[0]=0;

	for(int i=1;i<=n;i++)
		dp[i]=INT_MAX;

	for(int i=1;i<n+1;i++){
		for(int j=0;j<m;j++)
			if(a[j]<=i)
				dp[i]=min(dp[i],1+dp[i-a[j]]);
	}

	return dp[n];
}

int main(){
	int n,m;
	cin >> n >> m;

	int a[m];

	for(int i=0;i<m;i++)
		cin >> a[i];

	cout << getNumOfCoins(a,n,m);
}