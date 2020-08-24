#include<bits/stdc++.h>
using namespace std;

int solve(int costPerCut,int salePrice,vector<int>& v){
	int n=v.size();
	int mx=INT_MIN;

	for(int i=0;i<n;i++) mx=max(mx,v[i]);
	int ans=INT_MIN;

	for(int i=1;i<=mx;i++){
		int curr=0;
		for(int val:v){
			if(i>val) continue;

			int p=(val/i)*i*salePrice;
			int c=(val%i==0)?val/i-1:val/i;
			p-=c*costPerCut;

			if(p>0) curr+=p;
		}

		ans=max(ans,curr);
	}

	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
	#endif

	int costPerCut,salePrice;
	cin >> costPerCut >> salePrice;

	int n;
	cin >> n;
	vector<int> v(n);

	for(int i=0;i<n;i++) cin >> v[i];
	cout << solve(costPerCut,salePrice,v);
}