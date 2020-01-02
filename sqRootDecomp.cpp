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
int a[N],block[N];

void build(int n){
	int block_size=ceil(sqrt(n));

	fo(i,n) block[i/block_size]+=a[i];
}

void update(int l,int r,int n){
	int block_size=ceil(sqrt(n));
	block[l/block_size]+=r-a[l];
	a[l]=r;
}

ll query(int l,int r,int n){
	int block_size=ceil(sqrt(n));
	ll sum=0;

	while(l<r && l%block_size!=0){
		sum+=a[l];
		l++;
	}

	while((l+block_size)<=r){
		sum+=block[l/block_size];
		l+=block_size;
	}

	while(l<=r){
		sum+=a[l];
		l++;
	}

	return sum;

}

int main(){
	anuj;

	int n,type,l,r;
	cin >> n;

	fo(i,n) cin >> a[i];

	build(n);

	int q;
	cin >> q;

	while(q--){
		cin >> type >> l >> r;
		if(type==1) update(l,r,n);
		else cout << query(l,r,n) << endl;
	}
}
