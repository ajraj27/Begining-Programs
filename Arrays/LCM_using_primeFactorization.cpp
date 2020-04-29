//MXMMCM - codechef

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
const int N = 1e4+5;
const int LG = 20;
ll a[N],b[N];
vl v[N];

void seive(){
	for(int i=2;i<=N;i++){
		if(!b[i]){
			for(int j=i;j<=N;j+=i){
				b[j]=1;
				v[j].pb(i);
			}	
		}
		
	}
}

int main(){
	anuj;

	int t;
	cin >> t;
	seive();

	while(t--){
		ll n,m;
		cin >> n >> m;
		fo(i,n) cin >> a[i];

		ll b[N]={0};
		fo(i,n){
			for(ll x:v[a[i]]){
				ll k=0;
				while(a[i]%x==0){
					a[i]/=x;
					k++;
				}

				b[x]=max(b[x],k);
			}
		}

		// Till Now, b[] contains frequency of prime factors of LCM of array.
		// To get LCM of whole array , we traverse b[] and res*=pow(i,b[i]);

		ll ans=1;
		ll p=1;
		Fo(i,2,m+1){
			ll curr=1;
			ll j=i;
			for(ll x:v[j]){
				ll k=0;
				while(j%x==0){
					j/=x;
					k++;
					if(k>b[x]) curr*=x;
				}
			}

			if(curr>ans){
				ans=curr;
				p=i;
			}
		}

		cout << p << endl;


	}


}
