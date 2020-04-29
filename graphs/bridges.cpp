//FTALES - codechef
#include <bits/stdc++.h>
using namespace std;
#define anuj ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define ll long long int
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
int a[N];
vi g[N];
int in[N],low[N],vis[N];
int timer;
vpii edges;
map<pii,int> ma;

void dfs(int u,int p){
	vis[u]=1;
	in[u]=low[u]=timer;
	timer++;

	for(int v:g[u]){
		if(v==p) continue;
		if(vis[v]) low[u]=min(low[u],in[v]);
		else{
			dfs(v,u);
			if(low[v]>in[u]) ma[{min(u,v),max(u,v)}]=1;
			low[u]=min(low[u],low[v]);
		}
	}
}

int main(){
	anuj;

	int n,m,u,v;
	cin >> n >> m;

	while(m--){
		cin  >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		edges.pb({min(u,v),max(u,v)});
	}

	Fo(i,1,n+1) if(!vis[i]) dfs(i,0);
	int q;
	cin >> q;
	int ctr=0;

	while(q--){
		int x;
		cin >> x;
		x--;
		if(ma.find(edges[x])!=ma.end()) ctr++;
	}

	cout << ctr << endl;

}
