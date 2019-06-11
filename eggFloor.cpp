#include<bits/stdc++.h>
using namespace std;

int noOfMinTrials(int n,int e){
	int dp[n+1][e+1];

	for(int i=1;i<=n;i++)
		dp[i][1]=i;

	for(int i=1;i<=e;i++){
		dp[1][i]=1;
		dp[0][i]=0;
	}

	for(int i=2;i<=n;i++){
		for(int j=2;j<=e;j++){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=i;x++){
				int res=1+max(dp[x-1][j-1],dp[i-x][j]);
				if(res<dp[i][j])
					dp[i][j]=res;
			}
		}
	}

	return dp[n][e];

}



int main(){
	int n,e;
	cin >> n >> e;

	cout << noOfMinTrials(n,e);

	return 0;
}