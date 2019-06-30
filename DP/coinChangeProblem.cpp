#include<bits/stdc++.h>
using namespace std;

int noOfWays(vector<int> A,int B){
	int n=A.size();
	if(n==0)
		return 0;
	vector<int> dp(B+1,0);
	dp[0]=1;

	for(int i=0;i<n;i++){
		for(int j=A[i];j<=B;j++){
			dp[j]+=dp[j-A[i]];
		}
	}

	return dp[B];
}

int main(){
	int n,k;
	cin >> n >> k;

	vector<int> v(n);

	for(int i=0;i<n;i++) 
		cin >> v[i];

	cout << noOfWays(v,k);
}