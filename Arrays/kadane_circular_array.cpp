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

int kadane(int n){
	int max_so_far=0,curr_sum=0;

	fo(i,n){
		curr_sum+=a[i];

		if(curr_sum<0) curr_sum=0;
		else max_so_far=max(curr_sum,max_so_far);
	}

	return max_so_far;
}

int maxSumSubarrayInCircularArray(int n){
	// If all elements are negative
	int mx=INT_MIN;
	bool flag=false;
	fo(i,n){
		if(a[i]>=0) flag=true;
		mx=max(mx,a[i]);
	}

	if(!flag) return mx;

	//If atleast one element is positive
	int can1=kadane(n);
	int cum_sum=0;
	fo(i,n){
		cum_sum+=a[i];
		a[i]=-a[i];
	}

	int can2= cum_sum + kadane(n);

	return max(can1,can2);
}

int main(){
	anuj;

	int n;
	cin >> n;

	fo(i,n) cin >> a[i];

	cout << maxSumSubarrayInCircularArray(n);
}
