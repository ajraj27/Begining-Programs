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

bool check(string& s){
	map<char,int> m;
	int cnt=0;
	for(char ch:s) m[ch]++;
	for( auto x:m) if(x.second&1) cnt++;
	return cnt<=1;	
}

int32_t main(){
	anuj;

	while(1){
		string s;
		cin >> s;
		int n=s.length();
		if(s=="0") break;
		if(!check(s)){
			cout << "Impossible" << endl;
			continue;
		}

		int ans=0;
		fo(i,n/2){
			bool ok=false;
			for(int j=n-i-1;j>i;j--){
				if(s[i]==s[j]){
					ok=true;
					Fo(k,j,n-i-1){
						swap(s[k],s[k+1]);
						ans++;
					}

					break;
				}
			}

			if(!ok)
				Fo(k,i,n/2){
					swap(s[k],s[k+1]);
					ans++;
				}
		}

		cout << ans << endl;
	}
}