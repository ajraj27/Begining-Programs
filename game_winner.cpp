#include <bits/stdc++.h>	
using namespace std;
#define anuj ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long int
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define ll long long int
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define all(v)  sort(v.begin(),v.end())
#define rall(v) sort(v.rbegin(),v.rend())
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl '\n'
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
const int mod = 1000000007;
const int N = 2e5+5;
const int LG = 20;
int a[N];


int32_t main(){
	anuj;
	#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
	#endif

   string s;
   cin >> s;

   vector<string > res;
   int n=s.length();
   for(int i=0;i<n;i++){
   		int j=i+1;
   		while(j<n && s[j]==s[i]) j++;
   		res.push_back(s.substr(i,j-i));
   		i=j-1;
   }

   int w=0,b=0;

   for(string& str:res){
   		int l=str.length();
   		if(l>2 && str[0]=='w') w+=l-2;
   		if(l>2 && str[0]=='b') b+=l-2;
   }

   cout << (w>b?"wendy":"bob");
}