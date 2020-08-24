#include<bits/stdc++.h>
using namespace std;

#define int long long int

int dp[20][200][2];
vector<int> a;

map<int,int> m1,m2;

void getDigits(int x){
	a.clear();
	while(x){
		a.push_back(x%10);
		x/=10;
	}

	reverse(a.begin(),a.end());
}

int solve(int i,int sum,int tight,int f){
	if(i==(int)a.size()){
		if(!f) m1[sum]++;
		else m2[sum]++;

		return sum;
	}

	if(dp[i][sum][tight]!=-1) return dp[i][sum][tight];

	int lim=(tight?a[i]:9);

	int res=0;
	for(int j=0;j<=lim;j++){
		if(!tight || j<a[i]) res+=solve(i+1,sum+j,0,f);
		else res+=solve(i+1,sum+j,1,f);
	}

	return dp[i][sum][tight]=res;
}


vector<int> getAns(int x,int y){
	x--;
	m1.clear();m2.clear();

	getDigits(y);
	memset(dp,-1,sizeof(dp));
	int r=solve(0,0,1,0);

	getDigits(x);
	memset(dp,-1,sizeof(dp));
	int l=solve(0,0,1,1);

	
	for(auto z:m1) m1[z.first]-=m2[z.first];
	
	map<int,int> ans;

	for(auto z:m1) if(z.first>0 && z.second>0) ans[z.second]++;
	int p,q;
	
	for(auto z:ans){
		p=z.second;
		q=z.first;
	}

	return {p,q};	


}

int32_t main(){

	while(1){
		int x,y;
		cin >> x >> y;

		if(x==-1) break;

		auto z=getAns(x,y);
		cout << z[0] << " " << z[1] << endl;
	}
	
}