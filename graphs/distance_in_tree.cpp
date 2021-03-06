// No. of pair of nodes , whose distance between them is k.
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
const int N = 6e4;
const int LG = 20;
int a[N];
int dp[N][600];
vector<int> g[N];
int ans;

void dfs(int u,int p,int k){
	dp[u][0]=1;

	for(int v:g[u]){
		if(v==p) continue;
		dfs(v,u,k);
		Fo(i,1,k+1) ans+=dp[u][i-1]*dp[v][k-i];
		Fo(i,1,k+1) dp[u][i]+=dp[v][i-1];
	}
}

int main(){
	anuj;

	int n,k,u,v;
	cin >> n >> k;

	int x=n-1;
	while(x--){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1,0,k);
	cout << ans;
}
