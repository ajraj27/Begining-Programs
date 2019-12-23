#include<bits/stdc++.h>
using namespace std;

const int N= 1e6+5;
#define int long long int

int in[N],out[N],dp[N],val[N];
vector<int> g[N];

int maxi(int a,int b){
	return a>=b?a:b;
}

void dfs1(int u,int p){

	for(int v: g[u]){
		if(v==p) continue;
		dfs1(v,u);
		int t=maxi(0,val[v]-val[u]);
		in[u]=maxi(in[u],in[v]+t);
	}
}

void dfs2(int u,int p){
	int mx1=-1,mx2=-1,use,t,t1;

	for(int v: g[u]){
		if(v==p) continue;
		t=maxi(0,val[v]-val[u]);

		if(in[v]+t>=mx1){
			mx2=mx1;
			mx1=in[v]+t;
		}
		else if(mx2<in[v]+t)
			mx2=in[v]+t;
	}

	for(int v: g[u]){

		if(v==p) continue;
		t=maxi(0,val[v]-val[u]);
		t1=maxi(0,val[u]-val[v]);

		if(in[v]+t==mx1)
			use=mx2;
		else
			use=mx1;

		out[v]=maxi(t1+use,t1+out[u]);

		dfs2(v,u);
	}

}

int32_t main(){
	int n,m,u,v,node;
	cin >> n >> m;


	for(int i=1;i<=n;i++)
		cin >> val[i];

	int t=n-1;
	while(t--){
		cin >> u >> v;
		g[u+1].push_back(v+1);
		g[v+1].push_back(u+1);
	}

	dfs1(1,0);
	dfs2(1,0);

	for(int i=1;i<=m;i++){
		cin >> node;
		cout << maxi(in[node+1],out[node+1]) << endl;
	}

}