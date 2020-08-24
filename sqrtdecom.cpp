#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define m 1000000007

int32_t main(){
	#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
	#endif
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		int sq=ceil(sqrt(n));

		int dp1[n][sq+1],dp2[n][sq+1];

		for(int j=1;j<=sq;j++){
			for(int i=n-1;i>=0;i--)
				dp1[i][j]=(a[i]+(i+j<n?dp1[i+j][j]:0))%m;			
		}

		for(int j=1;j<=sq;j++){
			for(int i=n-1;i>=0;i--)
				dp2[i][j]=(a[i]*(i+j<n?dp2[i+j][j]:1))%m;			
		}

		int q;
		cin >> q;

		while(q--){
			int type,x,y;
			cin >> type >> x >> y;
			x--;
			if(type==0){
				if(y<sq) cout << dp1[x][y] << endl;
				else{
					int res=0;
					for(int i=x;i<n;i+=y) res=(res+a[i])%m;
					cout << res << endl;	
 				}
			} else{
				if(y<sq) cout << dp2[x][y] << endl;
				else{
					int res=1;
					for(int i=x;i<n;i+=y) res=(res*a[i])%m;
					cout << res << endl;	
 				}
			}
		}
	}
}