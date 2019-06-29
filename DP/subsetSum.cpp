#include<bits/stdc++.h>
using namespace std;

bool getMaxProfit(vector<int> A,int k){
	int n=A.size();

	if(n==0)
		return false;

	int possible[n+1][k+1];

	for(int i=0;i<=n;i++)
		possible[i][0]=true;

	for(int i=1;i<=k;i++)
		possible[0][i]=false;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			possible[i][j]=possible[i-1][j];
			if(j>=A[i-1])
				possible[i][j]|=possible[i-1][j-A[i-1]];
		}

	}

	return possible[n][k];
}



int main(){
	int n,k;
	cin >> n >> k;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin >> v[i];

	cout << getMaxProfit(v,k);
		
}