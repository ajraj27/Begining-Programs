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
const int N = 2e5;
const int LG = 20;

typedef struct data{
	data* child[26];
	int cnt;
}trie;

string a[N];
int n,k;
trie* root;
int ans;

void insert(string &s){
	trie* curr=root;
	fo(i,s.length()){
		char ch=s[i];
		int reqd=ch-'A';
		if(!curr->child[reqd]) curr->child[reqd]=new trie();
		curr=curr->child[reqd];
	}

	curr->cnt++;
}

void dfs(trie* curr,int lvl){

	fo(i,26){
		if(curr->child[i]){
			dfs(curr->child[i],lvl+1);
			curr->cnt+=curr->child[i]->cnt;
		}
	}

	while(curr->cnt>=k){
		curr->cnt-=k;
		ans+=lvl;
	}
}

int main(){
	anuj;
	#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
	#endif

	int t;
	cin >> t;

	for(int z=1;z<=t;z++){
		cin >> n >> k;
		root= new trie();
		ans=0;
		fo(i,n){
			cin >> a[i];
			insert(a[i]);
		}

		dfs(root,0);

		cout << "Case #" << z << ": " << ans << endl;


	}
}
