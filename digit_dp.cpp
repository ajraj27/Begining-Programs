#include<bits/stdc++.h>
using namespace std;

#define int long long int

int dp[20][200][2];
vector<int> a;

void getDigits(int x){
	a.clear();
	while(x){
		a.push_back(x%10);
		x/=10;
	}

	reverse(a.begin(),a.end());
}

int solve(int i,int sum,int tight){
	if(i==(int)a.size()) return sum;

	if(dp[i][sum][tight]!=-1) return dp[i][sum][tight];

	int lim=(tight?a[i]:9);

	int res=0;
	for(int j=0;j<=lim;j++){
		if(!tight || j<a[i]) res+=solve(i+1,sum+j,0);
		else res+=solve(i+1,sum+j,1);
	}

	return dp[i][sum][tight]=res;
}


int getAns(int x,int y){
	x--;

	getDigits(y);
	memset(dp,-1,sizeof(dp));
	int r=solve(0,0,1);

	getDigits(x);
	memset(dp,-1,sizeof(dp));
	int l=solve(0,0,1);

	return r-l;

}

int32_t main(){

	while(1){
		int x,y;
		cin >> x >> y;

		if(x==-1) break;

		auto z=getAns(x,y);
		cout << z << endl;
	}
	
}