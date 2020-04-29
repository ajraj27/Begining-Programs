//Tree Queries - Codeforces 629
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
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvll;
const int mod = 1000000007;
const int N = 2e5+5;
const int LG = 20;
int a[N];
int tin[N],tout[N],timer,dep[N],par[N];
vi g[N];

void dfs(int u,int p,int d=0){
	tin[u]=timer++;
	dep[u]=d;
	par[u]=p;

	for(int v:g[u]){
		if(v==p) continue;
		dfs(v,u,d+1);
	}

	tout[u]=timer++;
}

// is u is a ancestor of v
bool isAncestor(int u,int v){
	if(tin[u]<=tin[v] && tout[v]<=tout[u]) return true;
	return false;
}

int main(){
	anuj;
	#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
	#endif

	int n,q;
	cin >> n >> q;

	fo(i,n-1){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1,0);


	while(q--){
		int k;
		cin >> k;
		vi v(k);
		fo(i,k) cin >> v[i];

		int u=v[0];
		Fo(i,1,k) if(dep[v[i]]>dep[u]) u=v[i];

		fo(i,k){
			if(par[v[i]]==0) continue;
			v[i]=par[v[i]];
		}

		bool ok=true;

		fo(i,k) ok&=isAncestor(v[i],u);
		if(ok) cout << "YES" << endl;
		else cout << "NO"  << endl;


	}
}
