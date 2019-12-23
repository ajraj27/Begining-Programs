#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+5;

int in[N],out[N],dp[N];
vector<int> g[N];

void dfs1(int u,int p){

	in[u]=0;

	for(int v: g[u]){
		if(v==p) continue;
		dfs1(v,u);
		in[u]=max(in[u],1+in[v]);
	}
}

void dfs2(int u,int p){
	int mx1=-1,mx2=-1,use;

	for(int v: g[u]){
		if(v==p) continue;

		if(in[v]>=mx1){
			mx2=mx1;
			mx1=in[v];
		}
		else if(mx2<in[v])
			mx2=in[v];
	}

	for(int v: g[u]){

		if(v==p) continue;
		if(in[v]==mx1)
			use=mx2;
		else
			use=mx1;

		out[v]=max(2+use,1+out[u]);

		dfs2(v,u);
	}

}

int main(){
	int n,m,u,v;
	cin >> n >> m;

	while(m--){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs1(1,0);
	dfs2(1,0);

	for(int i=1;i<=n;i++){
		dp[i]=max(in[i],out[i]);
		cout << dp[i] << " ";
	}

}