#include <bits/stdc++.h>
using namespace std;
#define anuj ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl '\n'
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 2e5;
const int LG = 20;

int a[N], lvl[N], P[N][LG];
vi g[N];

void dfs(int u,int p){
	lvl[u]=lvl[p]+1;
	P[u][0]=p;

	for(int v:g[u]){
		if(v==p) continue;
		dfs(v,u);
	}
}

int lca(int u,int v){
	if(lvl[u]<lvl[v])
		swap(u,v);

	int lg;

	for(lg=0;(1<<lg)<=lvl[u];lg++);
	lg--;

	for(int i=lg;i>=0;i--)
		if(lvl[u]-(1<<i)>=lvl[v])
			u=P[u][i];

	if(u==v)
		return u;


	for(int i=lg;i>=0;i--)
		if(P[u][i]!=-1 && P[u][i]!=P[v][i])
			u=P[u][i],v=P[v][i];

	return P[u][0];				
	
}

//Ancestor of "u" at "dis" distance above from "u"
int getAncestor(int u,int dis){
	int lg;

	for(lg=0;(1<<lg)<=lvl[u];lg++);
	lg--;

	for(int i=lg;i>=0;i--)
		if((1<<i)<=dis)
			u=P[u][i],dis-=(1<<i);

	return u;	

}

int dis(int u,int v){
	if(lvl[u]<lvl[v]) swap(u,v);
	int w=lca(u,v);
	return lvl[u]+lvl[v]-2*lvl[w];
}

int main(){
	anuj;

	int n,m,u,v;
	cin >> n >> m;

	while(m--){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	lvl[0]=-1;
	fo(i,n+1) fo(j,LG) P[i][j]=-1;

	dfs(1,0);

	Fo(i,1,LG) 
		Fo(j,1,n+1)
			if(P[j][i-1]!=-1)
				P[j][i]=P[P[j][i-1]][i-1];

	cin >> u >> v;
	cout << getAncestor(u,v);		

}