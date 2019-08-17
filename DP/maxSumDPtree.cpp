#include<bits/stdc++.h>
using namespace std;


void dfs(int u,int a[],vector<int> list[],int dp[]){
	dp[u]=a[u];
	int mx=0;

	for(int x:list[u]){
		dfs(x,a,list,dp);
		mx=max(mx,dp[x]);
	}

	dp[u]+=mx;
}

int main(){
	int n,e,u,v;
	cin >> n >> e;

	int a[n+1],dp[n+1];
	vector<int> list[n+1];

	while(e--){
		cin >> u >> v;
		list[u].push_back(v);
	}

	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	dfs(1,a,list,dp);

	cout << dp[1];
}